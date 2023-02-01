#pragma once
#include <iostream>
//#include <iomanip>
#include <string>
#include <array>
#include <Ship.h>

static enum direction{
	UP=1,
	RIGHT,
	DOWN,
	LEFT
};

class Player {
private:
	std::array <bool, 100> shot_map{ false };		//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count;		//Количество оставшихся кораблей
public:
	Player(int count) :ship_count(count){
		navy.reserve(ship_count);
	}
	void setShip(int& _x, int& _y, int& _dir, int& _deck) {
		navy.emplace_back(Ship(_x, _y, _dir, _deck));
	}
	/*void shipInMap() {
		std::vector <std::pair<int, int >> temp;
		for ( const auto& it_navy : navy) {
			temp =it_navy.getCord();
			for (const auto& it_temp : temp) {
				shot_map [(it_temp.first-1)*10+it_temp.second]=true;
			}
		}
	}*/
	bool shot() {

	}

	//Проверка на наличие кораблей (если ноль- проиграл)
	//Размещение корабля на карте
	//Проверка выстрела (повторный выбор одного поля)
	//int getShipCount ()const;		Возвращает количество оставшихся кораблей
	//bool getMapCount (int x,int y)	Проверка попадания

};
