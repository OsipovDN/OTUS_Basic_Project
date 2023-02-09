#pragma once
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
	int pol;		//Размер игрового поля
	bool gm_over=false;	//Проверка конца игры
	bool input_mode=false;	//Способ расстановки кораблей
							//true-ручной, false- автоматический
	
public:
	//Конструктор (задает способ расстановки и размер поля)
	Game(bool m, int p=10);
	//Ручная расстановка кораблей
	void manSetShip();
	// Автоматическая расстановка кораблей
	std::unique_ptr<Player>&& autoSetShip(std::unique_ptr<Player>&& pl);
	//Проверка выхода за границу поля
	bool testCords(int& _x, int& _y, int& _dir, int& _deck);
	//Проверка наличия кораблей
	bool isOver();
};
