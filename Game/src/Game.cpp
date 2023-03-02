#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <iomanip>


//using Cords = std::pair<int, int>;
Game::Game() :menu(std::make_unique<Menu>()) {
	std::srand(static_cast <unsigned int>(time(nullptr)));
	//Вход в главное меню
	int val;
	val = menu->mainMenu();
	if (val == 3)
		EXIT_SUCCESS;
	//Ввод количества игроков
	numberOfPlayers();
	//Ввод размера игрового поля
	sizeOfTheField();
	//Ввод способа расстановки
	placementMode();

	plr1->print();
	plr2->print();
};

void Game::play() {
	Cords gen_cord;
	do {
		do {
			mapPol();
			std::cout << "Player 1's move:\n";
			gen_cord = setMove(plr1);
			menu->clrscr();
			plr2 = plr1->setShot(std::move(plr2), gen_cord, pol);

		} while (plr1->isMove() && plr2->ShipCount());
		if (!plr2->ShipCount()) {
			std::cout << "PLAYER 1 WON!!!\n";
			break;
		}
		if (multplr) {
			do {
				mapPol();
				std::cout << "Player 2's move:\n";
				gen_cord = setMove(plr2);
				menu->clrscr();
				plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);

			} while (plr2->isMove() && plr1->ShipCount());
			if (!plr1->ShipCount()) {
				std::cout << "PLAYER 2 WON!!!\n";
				break;
			}
		}
		else {
			do {
				gen_cord.first = autoSet(pol);
				gen_cord.second = autoSet(pol);
				mapPol();
				std::cout << "Player 2's move:\n";
				menu->clrscr();
				plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
			} while (plr2->isMove() && plr1->ShipCount());
			if (!plr1->ShipCount()) {
				std::cout << "PLAYER 2 WON!!!\n";
				break;
			}
		}
	} while (true);
};

void Game::numberOfPlayers() {
	int val;
	menu->setPlrVal(val);
	if (val == 1)
		multplr = false;
	else
		multplr = true;
};

void Game::sizeOfTheField() {
	menu->setPolVal(pol);
	plr1 = std::make_unique<Player>(pol);
	plr2 = std::make_unique<Player>(pol);
};

void Game::placementMode() {
	if (multplr) {
		for (int i = 1; i <= 2; ++i) {
			bool flag = menu->placement(i);
			if (i == 1)
				setNavy(plr1, flag);
			else
				setNavy(plr2, flag);
		}
	}
	else {
		bool flag = menu->placement(1);
		setNavy(plr1, flag);
		setNavy(plr2, false);
		menu->clrscr();
	}
};

void Game::setNavy(std::unique_ptr<Player>& pl, bool st) {
	Cords crd;
	int d = 0;
	if (st) {
		std::cout << "Manual entry of the location of ships:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "Enter the coordinates " << i
					<< "-х deck ship" << std::endl;
				for (;;) {
					crd = setMove(pl);
					std::cout << "Enter the direction (1-up, 2-right,3-down, 4-left): "
						<< std::endl;
					std::cin >> d;
					if (std::cin.fail() || d <= 0 || d > 4) {
						std::cin.clear();
						std::cin.sync();
						std::cin.ignore();
						menu->clrscr();
						std::cout << "An incorrect value was entered. Try again!\n";
						continue;
					}
					if (outOfBounds(crd, d, i)) {
						std::cout << "Going off the field! Try again"
							<< std::endl;
						continue;
					}
					if (pl->setShip(crd, d, i)) {
						std::cout << "There is an intersection with another ship! Try again."
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
					crd.first = autoSet(pol);
					crd.second = autoSet(pol);
					d = autoSet(4);
					if (outOfBounds(crd, d, i))
						continue;
					if (!pl->setShip(crd, d, i))
						continue;
					else
						break;
				}
			}
		}
	}
};

Game::Cords&& Game::setMove(const std::unique_ptr<Player>& pl)const {
	Cords crd;
	int count = 0;
	for (;;) {
		//Проверка сделанного хода
		std::cout << "Enter the coordinates (x ,y) separated by a space: "
			<< std::endl;
		std::cout << "x,y: ";
		std::cin >> crd.first >> crd.second;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore();
			menu->clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		if (crd.first <= 0 || crd.second <= 0 || crd.first > pol || crd.second > pol) {
			std::cout << "Going off the field! Try again"
				<< std::endl;
			continue;
		}
		count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
		if (pl->isRepeat(crd, pol)) {
			std::cout << "A shot has already been fired at this position." <<
				std::endl;
			std::cout << "Try again." << std::endl;
			continue;
		}
		else {
			return std::move(crd);
		}
	}
};

inline int Game::autoSet(int p)const {
	int val = std::rand() % p + 1;
	return val;
};

bool Game::outOfBounds(Cords& crd, int& _dir, int& _deck) {
	if (crd.first <= 0 || crd.second <= 0 || crd.first > pol || crd.second > pol)
		return true;
	if (_dir == 1)
		return ((crd.second - _deck) <= 0);
	else if (_dir == 2)
		return ((crd.first + _deck) > pol);
	else if (_dir == 3)
		return ((crd.second + _deck) > pol);
	else
		return ((crd.first - _deck) <= 0);
};

void Game::mapPol() {
	int s = 1;
	auto temp_map_pl1 = plr1->getMap();
	auto temp_map_pl2 = plr2->getMap();
	std::cout << std::setw(pol / 2) << "\tPlayer 1" << std::setw(pol / 2) << "\tPlayer 2" << std::endl;
	for (int i = 0; i < 2; ++i) {
		std::cout << std::setw(3);
		for (int j = 1; j <= pol; ++j) {
			std::cout << j << " ";
		}
		std::cout << "\t";
	}
	std::cout << std::endl;;
	auto it_start1 = temp_map_pl1.cbegin();
	auto it_start2 = temp_map_pl2.cbegin();
	do {
		if (s >= 10)
			std::cout << s << "";
		else
			std::cout << s << std::setw(2);
		it_start2 = colorOutput(it_start2);
		std::cout << std::setw(4); //"\t\t";
		if (s >= 10)
			std::cout << s << " ";
		else
			std::cout << s << std::setw(2);
		it_start1 = colorOutput(it_start1);
		std::cout << "\n";
		s++;
	} while (it_start1 != temp_map_pl1.cend() || it_start2 != temp_map_pl2.cend());
};

std::vector<char>::const_iterator Game::colorOutput(std::vector<char>::const_iterator it_begin) {
	std::for_each(it_begin, it_begin + pol, [&](const char pos) {
		if (pos == 'X')
			menu->chengeColor(4);
		else if (pos == '+')
			menu->chengeColor(10);
		std::cout << pos << " ";
		menu->chengeColor(15);
		});
	return it_begin + pol;
};






