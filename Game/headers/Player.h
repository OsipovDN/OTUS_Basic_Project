#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>


class Player {
private:
	std::array <char, 100> map_shot{};//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count;		//Количество оставшихся кораблей
public:
	explicit Player(int count);
	//Размещение корабля на карте
	bool setShip(int _x, int _y, int _dir, int _deck);
	//Проверка пересечения кораблей
	bool intersecShip(int& _x, int& _y, int& _dir, int& _deck) noexcept;
	//Проверка попадания
	bool getShot(int& _x, int& _y);
	//Проверка выстрела
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr);
	//Проверка наличия кораблей
	int ShipCount()const { return ship_count; };

	//Массив периметра корабля
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/

	//Для проверки работы
	void print();

	std::array<char,100>* getMap() {
		return &map_shot;

	}
};

	

	
