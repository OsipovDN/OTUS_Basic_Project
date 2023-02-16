#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>


class Player {
private:
	using Cords = std::pair<int, int>;
	std::array <char, 100> map_shot{};//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count;		//Количество оставшихся кораблей
public:
	explicit Player(int count);
	//Размещение корабля на карте
	bool setShip(Cords c, int _dir, int _deck);
	//Проверка пересечения кораблей
	bool intersecShip(Cords& c, int& _dir, int& _deck) noexcept;
	//Проверка выстрела
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr);
	//Проверка попадания
	bool getShot(Cords& crd);
	//Проверка наличия кораблей
	int ShipCount()const { return ship_count; };
	//Передача карты игрока для печати
	std::array<char, 100>* getMap() { return &map_shot; }
	//Для проверки работы
	void print();

	//Массив периметра корабля
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/

	

	
};

	

	
