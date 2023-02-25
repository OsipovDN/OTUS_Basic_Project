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
	int pol;				//Размер игрового поля
	//bool gm_over = false;	//Проверка конца игры
	bool multplr = false;		//true-два игрока, false- один игрок
	

public:
	//Конструктор (задает способ расстановки и размер поля)
	Game();
	//Запуск игры
	void play();
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
	
};

