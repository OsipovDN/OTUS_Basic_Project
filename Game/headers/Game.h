#pragma once
#include "Player.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>


//static enum direction{
//	UP=1,
//	RIGHT,
//	DOWN,
//	LEFT
//} dir;

class Game {
private:

	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	int pol;		//Размер игрового поля
	bool gm_over = false;	//Проверка конца игры
	bool input_mode = false;	//Способ расстановки кораблей
							//true-ручной, false- автоматический

public:
	//Конструктор (задает способ расстановки и размер поля)
	Game(bool m = false, int p = 10);
	//Ручная расстановка кораблей
	void manSetShip();
	// Автоматическая расстановка кораблей
	std::unique_ptr<Player>&& autoSetShip(std::unique_ptr<Player>&& pl);
	//Проверка выхода за границу поля
	bool testCords(int& _x, int& _y, int& _dir, int& _deck);
	//Вывод карты ироков на экран
	//Запуск игры
	void play();
	//Проверка наличия кораблей
	bool isOver();

	void mapPol( ) {
		int s = 1;
		auto *temp_map_pl1 = plr1->getMap();
		auto *temp_map_pl2 = plr2->getMap();
		std::cout << "\tИгрок 1" << "\t\t\t\tИгрок 2" << std::endl;
		for (int i = 0; i < 2; ++i) {
			std::cout<<"   ";
			for (int j = 1; j <= pol; ++j) {
				std::cout << j << " ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;;
		auto it_start1 = temp_map_pl1->cbegin();
		auto it_start2 = temp_map_pl2->cbegin();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		do {
			if (s==10)
				std::cout << s << " ";
			else
				std::cout << s << "  ";
			std::for_each(it_start2, it_start2 + pol, [&](const char pos) {
				if (pos == 'X') 
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				else if (pos == '+')
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				std::cout << pos << " ";
				SetConsoleTextAttribute(hConsole, 15);
				});
			it_start2 += 10;
			std::cout << "\t\t";
			if (s == 10)
				std::cout << s << " ";
			else
				std::cout << s << "  ";
			std::for_each(it_start1, it_start1 + pol, [&](const char pos) {
				if (pos == 'X')
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				else if (pos == '+')
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				std::cout << pos << " ";
				SetConsoleTextAttribute(hConsole, 15);
				});
			it_start1 += 10;
			std::cout << "\n";
			s++;
		} while (it_start1 != temp_map_pl1->cend()||it_start2!=temp_map_pl2->cend());
	}
};

