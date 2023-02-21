#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <Windows.h>

//using Cords = std::pair<int, int>;
Game::Game() :menu(std::make_unique<Menu>()) {
	int val;
	std::srand(static_cast <unsigned int>(std::time(0)));
	//���� � ������� ����
	val = menu->mainMenu();
	if (val == 3)
		exit(1);
	//���� ���������� �������
	val = menu->setPlrVal();
	if (val == 1)
		multplr = false;
	else
		multplr = true;
	//���� ������� �������� ����
	pol = menu->setPolVal();
	plr1 = std::make_unique<Player>(pol);
	plr2 = std::make_unique<Player>(pol);
	//���� ������� �����������
	if (multplr) {
		for (int i = 1; i <= 2; ++i) {
			bool flag = menu->placement(i);
			if (i == 1) {
				setNavy(plr1, flag);
				system("cls");
			}
			else {
				setNavy(plr2, flag);
				system("cls");
			}
		}
	}
	else {
		bool flag = menu->placement(1);
		setNavy(plr1, flag);
		setNavy(plr2, false);
		system("cls");
	}
	std::srand(static_cast <unsigned int>(time(nullptr)));
	plr1->print();
	plr2->print();
};

void Game::play() {
	Cords gen_cord;
	do {
		do {
			mapPol();
			std::cout << "��� ������ 1:\n";
			gen_cord = setMove(plr1);
			plr2 = plr1->setShot(std::move(plr2), gen_cord, pol);
			
		} while (plr1->isMove()&& plr2->ShipCount());
		if (!plr2->ShipCount()) {
			std::cout << "����� 1 �������!!!\n";
			break;
		}
		if (multplr) {
			do {
				mapPol();
				std::cout << "��� ������ 2:\n";
				gen_cord = setMove(plr2);
				plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
				
			} while (plr2->isMove()&& plr1->ShipCount());
			if (!plr1->ShipCount()) {
				std::cout << "����� 2 �������!!!\n";
				break;
			}
		}
		else {	
			do {
				gen_cord.first = autoSet(pol);
				gen_cord.second = autoSet(pol);
				mapPol();
				std::cout << "��� ������ 2:\n";
				plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
			} while (plr2->isMove() && plr1->ShipCount());
			if (!plr1->ShipCount()) {
				std::cout << "����� 2 �������!!!\n";
				break;
			}
		}
	} while (true);
};

void Game::setNavy(std::unique_ptr<Player>& pl, bool st) {
	Cords crd;
	int d = 0;
	if (st) {
		std::cout << "������ ���� ������������ ��������:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "������� ���������� " << i
					<< "-� ��������� �������" << std::endl;
				for (;;) {
					crd = setMove(pl);
					std::cout << "������� ����������� (1-�����,2-������,3-����,4-�����): "
						<< std::endl;
					std::cin >> d;
					if (outOfBounds(crd, d, i)) {
						std::cout << "����� �� ������� ����! ���������� �����"
							<< std::endl;
						continue;
					}
					if (pl->setShip(crd, d, i)) {
						std::cout << "���� ����������� � ������ ��������! ���������� �����."
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
		//�������� ���������� ����
		std::cout << "������� ���������� (x ,y) ����� ������: "
			<< std::endl;
		std::cout << "x,y: ";
		std::cin >> crd.first >> crd.second;
		if (crd.first <= 0 || crd.second <= 0 || crd.first > pol || crd.second > pol) {
			std::cout << "����� �� ������� ����! ���������� �����"
				<< std::endl;
			continue;
		}
		count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
		if (pl->isRepeat(crd, pol)) {
			std::cout << "�� ������ ������� ����� ��� ��� ������ �������." <<
				std::endl;
			std::cout << "��������� ����." << std::endl;
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
	std::cout << "\t����� 1" << "\t\t\t\t����� 2" << std::endl;
	for (int i = 0; i < 2; ++i) {
		std::cout << "   ";
		for (int j = 1; j <= pol; ++j) {
			std::cout << j << " ";
		}
		std::cout << "\t";
	}
	std::cout << std::endl;;
	auto it_start1 = temp_map_pl1.cbegin();
	auto it_start2 = temp_map_pl2.cbegin();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		if (s >= 10)
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
		it_start2 += pol;
		std::cout << "\t\t";
		if (s >= 10)
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
		it_start1 += pol;
		std::cout << "\n";
		s++;
	} while (it_start1 != temp_map_pl1.cend() || it_start2 != temp_map_pl2.cend());
};

bool Game::isOver() {
	if (!plr1->ShipCount()) {
		std::cout << "����� 2 �������!" << std::endl;
		return true;
	}
	if (!plr2->ShipCount()) {
		std::cout << "����� 1 �������!" << std::endl;
		return true;
	}
	return false;
};



