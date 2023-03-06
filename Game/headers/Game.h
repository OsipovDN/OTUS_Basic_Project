#pragma once
#include "Player.h"
#include "Menu.h"
#include <iostream>
//#include <Windows.h>

class Game {
private:

	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	std::unique_ptr<Menu> menu;
	int pol = 10;				//Размер игрового поля
	//bool gm_over = false;	//Проверка конца игры
	bool multplr = false;		//true-два игрока, false- один игрок


public:
	//Конструктор (задает способ расстановки и размер поля)
	Game();
	//Запуск игры
	void play();
	//Задает количество игроков
	void numberOfPlayers();
	//Задает размер игрового поля
	void sizeOfTheField();
	//Режим расстановки кораблей
	void placementMode();
	//Расстановка флота
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//Ввод координат
	Cords&& setMove(const std::unique_ptr<Player>& pl)const;
	//Сделать выстрел
	char setShot(const std::unique_ptr<Player>& pl1, const std::unique_ptr<Player>& pl2, Cords& crd)noexcept;
	//Автоматический расчет координат
	inline int autoSet(int& p)const;
	//Проверка выхода за границу поля
	bool outOfBounds(Cords& crd, int& _dir, int& _deck)const noexcept;
	//Вывод ироков на экран
	void mapPol();
	//Задает цвет клетке
	std::vector<char>::const_iterator colorOutput(std::vector<char>::const_iterator it_begin);



	
	

};

