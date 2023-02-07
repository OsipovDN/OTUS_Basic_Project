#pragma once
#include <iostream>
#include <memory>
#include "Player.h"

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
	bool gm_over=false;	//Проверка конца игры
public:
	//Конструктор
	explicit Game(int s=10) :plr1(std::make_unique<Player>(s)), 
		plr2(std::make_unique<Player>(s)) {};
	//Способ расстановки 
	void ManSetShip() {
		int x = 0;
		int y = 0;
		std::string d;
		std::cout << "Ручной ввод расположения кораблей:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "Введите " << j << "-й " << i << "-й корабль: "
					<< std::endl;
				std::cout << "x= ";
				std::cin >> x;
				std::cout << "y= ";
				std::cin >> y;
				std::cout << "Направление (1-вверх,2-вправо,3-вниз,4-влево): ";

				navy.emplace_back(Ship(x, y, std::stoi(d), i));
			}
		}
	}
	
	// (авто или ручной режим), расстановка кораблей противника)

	
	//Проверка выхода за границу поля
	//Проверка наличия кораблей
	//Расстановка кораблей


};
