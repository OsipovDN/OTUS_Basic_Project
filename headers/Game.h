#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
	bool gm_over=false;	//Проверка конца игры
public:
	//Конструктор
	explicit Game(int s=10) :plr1(std::make_unique<Player>(s)), 
		plr2(std::make_unique<Player>(s)) {};
	//Ручной способ расстановки
	void manSetShip() {
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
				std::cout << "x,y,dir: ";
				std::cin >> x >> y >> d;
				plr1->setShip(x, y, d, i);
			}
		}
	}
	void autoSetShip() {
	
	}
	
	// (авто или ручной режим), расстановка кораблей противника)

	
	//Проверка выхода за границу поля
	//Проверка наличия кораблей
	//Расстановка кораблей


};
