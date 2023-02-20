#pragma once
#include "Player.h"
#include "Menu.h"

class Game {

private:
	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	int pol;		//Размер игрового поля
	bool gm_over = false;	//Проверка конца игры
	//bool input_navy = false;	//Способ расстановки кораблей
							//true-ручной, false- автоматический
	bool multplr=false;		//true-два игрока, false- один игрок

public:
	//Конструктор (задает способ расстановки и размер поля)
	Game(); 
	//Запуск игры
	void play();
	//Автоматический расчет координат
	int autoSet(int p);
	//Проверка выхода за границу поля
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//Вывод  ироков на экран
	void mapPol();
	//Проверка наличия кораблей
	bool isOver();
	//Расстановка флота
	void setNavy(std::unique_ptr<Player>& pl, bool st);
};

