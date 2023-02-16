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
	bool gm_over = false;	//Проверка конца игры
	//bool input_navy = false;	//Способ расстановки кораблей
							//true-ручной, false- автоматический
	bool multplr=false;		//true-два игрока, false- один игрок

public:
	//Конструктор (задает способ расстановки и размер поля)
	Game(int p = 10); 
	//Запуск игры
	void play();
	//Автоматический расчет координат
	int autoSet(int p) {
		int val = std::rand() % p + 1;
		return val;
	}
	//Ручная расстановка кораблей
	//void manSetShip();
	// Автоматическая расстановка кораблей
	//std::unique_ptr<Player>&& autoSetShip(std::unique_ptr<Player>&& pl);
	//Проверка выхода за границу поля
	bool testCords(int& _x, int& _y, int& _dir, int& _deck);
	//Вывод карты ироков на экран
	void mapPol();
	//Проверка наличия кораблей
	bool isOver();

	void setNavy(std::unique_ptr<Player>& pl, bool st);
};

