#pragma once
#include "Player.h"
#include "Menu.h"
//#include <Windows.h>

class Game {
private:

	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	std::unique_ptr<Menu> menu;
	int pol = 10;				//������ �������� ����
	//bool gm_over = false;	//�������� ����� ����
	bool multplr = false;		//true-��� ������, false- ���� �����


public:
	//����������� (������ ������ ����������� � ������ ����)
	Game();
	//������ ����
	//void play();
	//������ ���������� �������
	void numberOfPlayers();
	//������ ������ �������� ����
	void sizeOfTheField();
	//����� ����������� ��������
	void placementMode();
	//����������� �����
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//���� ���������
	Cords&& setMove(const std::unique_ptr<Player>& pl)const;
	//�������������� ������ ���������
	inline int autoSet(int p)const;
	//�������� ������ �� ������� ����
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//����� ������ �� �����
	void mapPol();
	//������ ���� ������
	std::vector<char>::const_iterator colorOutput(std::vector<char>::const_iterator it_begin);



	void Game::play() {
		Cords gen_cord;
		char pos;
		do {
			do {
				mapPol();
				std::cout << "Player 1's move:\n";
				gen_cord = setMove(plr1);
				menu->clrscr();
				/*plr2 = plr1->setShot(std::move(plr2), gen_cord, pol);*/
				pos = setShot(plr1, plr2, gen_cord);
				plr1->setPoint(gen_cord, pol, pos);

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
					//plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
					pos = setShot(plr2, plr1, gen_cord);
					plr2->setPoint(gen_cord, pol, pos);

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
					//plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
					pos = setShot(plr1, plr2, gen_cord);
					plr1->setPoint(gen_cord, pol, pos);
				} while (plr2->isMove() && plr1->ShipCount());
				if (!plr1->ShipCount()) {
					std::cout << "PLAYER 2 WON!!!\n";
					break;
				}
			}
		} while (true);
	};

	char setShot(std::unique_ptr<Player>& plr1, std::unique_ptr<Player>& plr2, Cords& crd)noexcept {
		bool flag = plr2->getShot(crd);
		if (flag) {
			plr1->moveStat(flag);
			return 'X';
		}
		else {
			plr1->moveStat(flag);
			return '+';
		}
	};

};

