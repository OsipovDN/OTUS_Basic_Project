#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <rand>
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
	bool input_mode;	//true-ручной, false- автоматический
	int pol;

public:
	//Конструктор
	explicit Game(bool m,int s = 10) :plr1(std::make_unique<Player>(s)),
		plr2(std::make_unique<Player>(s)),input_mode(m), pol (s) {
		if (input_mode) {
			manSetShip();
			autoSetShip(plr1);
		}
		else {
			autoSetShip(plr1);
			autoSetShip(plr2);
		}
	};
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
				for (;;) {
					std::cout << "x,y,dir: ";
					std::cin >> x >> y >> d;
					if (testCords(x, y, d, i)) {
						std::cout << "Выход за пределы поля! Попробуйте снова" << std::endl;
						continue;
					}
					if (!plr1->setShip(x, y, d, i)) {
						std::cout << "Есть пересечение с лругим кораблем! Попробуйте снова."
							<< std::endl;
						continue;
					}
					else
						break;
				}
			}
		}
	}
	// Автоматическая расстановка кораблей
	void autoSetShip(Player& pl) {
		std::srand(std::time(nullptr));
		int x = 0;
		int y = 0;
		int d = 0;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				for (;;) {
					x = std::rand() % 10 + 1;
					y = std::rand() % 10 + 1;
					d = std::rand() % 4 + 1;
					if (testCords(x, y, d, i))
						continue;
					if (!pl->setShip(x, y, d, i))
						continue;
					else
						break;
				}
			}
		}
	}
	
	

	
	//Проверка выхода за границу поля
	bool testCords(int& _x, int& _y, int& _dir, int& _deck) {
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
