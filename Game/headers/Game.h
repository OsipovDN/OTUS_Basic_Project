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
	//void play();
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
	//Автоматический расчет координат
	inline int autoSet(int p)const;
	//Проверка выхода за границу поля
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//Вывод ироков на экран
	void mapPol();
	//Задает цвет клетке
	std::vector<char>::const_iterator colorOutput(std::vector<char>::const_iterator it_begin);



	void Game::play() {
		Cords gen_cord;
		char pos;
		int pl;
		do {
			do {
				mapPol();
				std::cout << "Player 1's move:\n";
				pl = 1;
				gen_cord = setMove(plr1);
				menu->clrscr();
				/*plr2 = plr1->setShot(std::move(plr2), gen_cord, pol);*/
				pos = setShot(pl, gen_cord);
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
					pl = 2;
					gen_cord = setMove(plr2);
					menu->clrscr();
					//plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
					pos = setShot(pl, gen_cord);
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
					pl = 2;
					menu->clrscr();
					//plr1 = plr2->setShot(std::move(plr1), gen_cord, pol);
					pos = setShot(pl, gen_cord);
					plr1->setPoint(gen_cord, pol, pos);
				} while (plr2->isMove() && plr1->ShipCount());
				if (!plr1->ShipCount()) {
					std::cout << "PLAYER 2 WON!!!\n";
					break;
				}
			}
		} while (true);
	};

	char setShot(int& pl, Cords& crd)noexcept {
		bool flag;
		if (pl == 1) {
			flag = plr2->getShot(crd);
			if (flag) {
				plr1->moveStat(true);
				plr2->moveStat(false);
				return 'X';
			}
			else {
				plr1->moveStat(false);
				plr2->moveStat(true);
				return '+';
			}
		}
		else {
			flag = plr1->getShot(crd);
			if (flag) {
				plr2->moveStat(true);
				plr1->moveStat(false);
				return 'X';
			}
			else {
				plr2->moveStat(false);
				plr1->moveStat(true);
				return '+';
			}
		}
	};

};

