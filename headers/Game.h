#pragma once
#include <iostream>
#include <string>
#include <vector>
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
	int pol;
public:
	//Конструктор
	explicit Game(int s = 10) :plr1(std::make_unique<Player>(s)),
		plr2(std::make_unique<Player>(s)), pol = s {};
	//Ручная расстановка кораблей
	void manSetShip() {
		int x = 0;
		int y = 0;
		int d = 0;
		std::cout << "Ручной ввод расположения кораблей:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "Введите координаты и направление " << j << "-х палубного корабля"
					<< std::endl;
				std::cout << "Направление (1-вверх,2-вправо,3-вниз,4-влево): " << std::endl;
				std::cout << "x,y,dir: ";
				do {
					std::cin >> x >> y >> d;
				} while (testCords(x, y, d, i));
				plr1->setShip(x, y, d, i);
			}
		}
	}
	// Автоматическая расстановка кораблей
	void autoSetShip() {
		
	}
	
	

	
	//Проверка выхода за границу поля
	bool testCords(int _x, int _y, int _dir, int _deck) {
		if (_x <= 0 || _y <= 0 || _x > pol || _y > pol)
			return true;
		if (_dir == 1)
			return ((_x - _deck) <= 0);
		else if (_dir == 2)
			return ((_y + _deck) > pol);
		else if (_dir == 3)
			return ((_x - _deck) > pol);
		else 
			return ((_y - _deck) <= 0);
	}
	//Проверка наличия кораблей
	//Расстановка кораблей


};
