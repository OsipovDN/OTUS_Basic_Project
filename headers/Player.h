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
	std::vector<Ship> navy;
	int ship_count;		//Количество оставшихся кораблей
public:
	Player(int count) :ship_count(count){
		navy.reserve(ship_count);
	}
	//Размещение корабля на карте
	//!!!!!!!
	void setShip(int& _x, int& _y, int& _dir, int& _deck) {
		navy.emplace_back(Ship(_x, _y, _dir, _deck));
	}
	//Проверка пересечения кораблей
	bool intersecShip(int& _x, int& _y, int& _dir, int& _deck) {
		if (_dir == 1 || _dir == 3) {
			if (_dir == 1) {
				
			}
			else {}
		}
		else {
			if (_dir == 2) {

			}
		}
	}

	//Проверка попадания
	bool getShot(int& _x,int& _y) {
		bool flag=false;
		std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship& s) {
			flag = s.IsHit(_x, _y); 
			if (!s.Islife())
				ship_count--;
			});
		return flag;
	}
	
	//Проверка наличия кораблей
	bool ShipCount()const {
		return ship_count;
	};
};
