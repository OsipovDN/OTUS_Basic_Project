#pragma once
#include <iostream>
//#include <iomanip>
#include <string>
#include <array>
#include <algorithm>
#include <execution>
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
	//Размещение корабля на карте
	void setShip(int& _x, int& _y, int& _dir, int& _deck) {
		navy.emplace_back(Ship(_x, _y, _dir, _deck));
	}

	//Проверка попадания
	bool getShot(int& _x,int& _y) {
		bool flag=false;
		std::for_each(std::execution::par, navy.begin(), navy.end(), [&](Ship& s) {
			flag = s.IsHit(_x, _y); 
			if (!s.Islife())
				ship_count--;
			});
		return flag;
	}

	//Проверка выстрела (повторный выбор одного поля)
	bool setShot(int& _x, int& _y){
		int count = ((_x - 1) * 10 + _y) - 1;
		if (!shot_map[count]) {
			shot_map[count] = true;
			return true;
		}
		return false;
	}
	
	//Проверка наличия кораблей
	bool ShipCount()const {
		return ship_count;
	};
};
