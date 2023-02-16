#include "Game.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <Windows.h>

Game::Game(int p) :plr1(std::make_unique<Player>(10)),
plr2(std::make_unique<Player>(10)), pol(p) {
	int val;
	std::srand(static_cast <unsigned int>(std::time(0)));
	//Ввод количества игроков
	for (;;) {
		std::cout << "Выбирете количество игроков" << std::endl;
		std::cout << "Один игрок-1\nДва игрока-2\nВыход-0\n-> ";
		std::cin >> val;
		if (val != 1 && val != 2 && val != 0) {
			std::cout.flush();
			std::cout << "Некорректный ввод. Попробуйте еще раз!\n";
			continue;
		}
		else
			break;
	}
	if (val == 0)
		exit(1);
	if (val == 2)
		multplr = true;
	//Ввод способа расстановки
	
		std::cout.flush();
		std::cout << "Игрок 1\n";
		std::cout << "Введите способ расстановки флота (1- ручной,2- автоматический)\n-> ";
		std::cin >> val;
		if (val == 1)
			setNavy(plr1,true);
		else
			setNavy(plr1, false);
		if (multplr) {
			std::cout.flush();
			std::cout << "Игрок 2\n";
			std::cout << "Введите способ расстановки флота (1- ручной,2- автоматический)\n-> ";
			std::cin >> val;
			if (val == 1)
				setNavy(plr2, true);
			else
				setNavy(plr2, false);
		}
		else
			setNavy(plr2, false);

	/*if (input_navy) {
		manSetShip();
		plr1 = autoSetShip(std::move(plr1));
	}
	else {
		plr1 = autoSetShip(std::move(plr1));
		plr2 = autoSetShip(std::move(plr2));
	}*/
	std::srand(static_cast <unsigned int>(time(nullptr)));
	plr1->print();
	plr2->print();
};

void Game::play() {
	for (;;) {
		mapPol();
		std::cout << "Ход игрока 1:\n";
		plr2 = plr1->setShot(std::move(plr2));
		mapPol();
		std::cout << "Ход игрока 2:\n";
		plr1 = plr2->setShot(std::move(plr1));
	}
};

//void Game::manSetShip() {
//	int x = 0;
//	int y = 0;
//	int d = 0;
//	std::cout << "Ручной ввод расположения кораблей:"
//		<< std::endl;
//	for (int i = 4; i > 0; --i) {
//		for (int j = 4; j >= i; --j) {
//			std::cout << "Введите координаты и направление " << i
//				<< "-х палубного корабля"<< std::endl;
//			std::cout << "Направление (1-вверх,2-вправо,3-вниз,4-влево): " 
//				<< std::endl;
//			for (;;) {
//				std::cout << "x,y,dir: ";
//				std::cin >> x >> y >> d;
//				if (testCords(x, y, d, i)) {
//					std::cout << "Выход за пределы поля! Попробуйте снова" 
//						<< std::endl;
//					continue;
//				}
//				if (!plr1->setShip(x, y, d, i)) {
//					std::cout << "Есть пересечение с лругим кораблем! Попробуйте снова."
//						<< std::endl;
//					continue;
//				}
//				else
//					break;
//			}
//		}
//	}
//};

/*td::unique_ptr<Player>&& Game::autoSetShip(std::unique_ptr<Player>&& pl) {
	int x = 0;
	int y = 0;
	int d = 0;
	for (int i = 4; i > 0; --i) {
		for (int j = 4; j >= i; --j) {
			for (;;) {
				x = autoSet(pol);
				y = autoSet(pol);
				d = autoSet(4);
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
};*/

bool Game::testCords(int& _x, int& _y, int& _dir, int& _deck) {
	if (_x <= 0 || _y <= 0 || _x > pol || _y > pol)
		return true;
	if (_dir == 1)
		return ((_x - _deck) <= 0);
	else if (_dir == 2)
		return ((_y + _deck) > pol);
	else if (_dir == 3)
		return ((_x + _deck) > pol);
	else
		return ((_y - _deck) <= 0);
};

void Game::mapPol() {
	int s = 1;
	auto* temp_map_pl1 = plr1->getMap();
	auto* temp_map_pl2 = plr2->getMap();
	std::cout << "\tИгрок 1" << "\t\t\t\tИгрок 2" << std::endl;
	for (int i = 0; i < 2; ++i) {
		std::cout << "   ";
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
		if (s == 10)
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
	} while (it_start1 != temp_map_pl1->cend() || it_start2 != temp_map_pl2->cend());
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

void Game::setNavy(std::unique_ptr<Player>& pl, bool st) {
	int x = 0;
	int y = 0;
	int d = 0;
	if (st) {
		std::cout << "Ручной ввод расположения кораблей:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "Введите координаты и направление " << i
					<< "-х палубного корабля" << std::endl;
				std::cout << "Направление (1-вверх,2-вправо,3-вниз,4-влево): "
					<< std::endl;
				for (;;) {
					std::cout << "x,y,dir: ";
					std::cin >> x >> y >> d;
					if (testCords(x, y, d, i)) {
						std::cout << "Выход за пределы поля! Попробуйте снова"
							<< std::endl;
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
	else {
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				for (;;) {
					x = autoSet(pol);
					y = autoSet(pol);
					d = autoSet(4);
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
};