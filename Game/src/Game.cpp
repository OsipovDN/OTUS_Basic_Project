
#include "Game.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <ctime>

Game::Game(bool m, int p):plr1(std::make_unique<Player>(10)),
plr2(std::make_unique<Player>(10)), pol(p), input_mode(m) {
	std::srand(static_cast <unsigned int>(std::time(0)));
	if (input_mode) {
		manSetShip();
		plr1 = autoSetShip(std::move(plr1));
	}
	else {
		plr1 = autoSetShip(std::move(plr1));
		plr2 = autoSetShip(std::move(plr2));
	}
	plr1->print();
	plr2->print();
};

void Game::manSetShip() {
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
};

std::unique_ptr<Player>&& Game::autoSetShip(std::unique_ptr<Player>&& pl) {
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
	return std::move(pl);
};

bool Game::testCords(int& _x, int& _y, int& _dir, int& _deck) {
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
};

bool Game::isOver() {
	if (!plr1->ShipCount()) {
		std::cout << "Игрок 2 выиграл!" << std::endl;
		return true;
	}
	if (!plr2->ShipCount()) {
		std::cout << "Игрок 1 выиграл!" << std::endl;
		return true;
	}
	return false;
};