#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>


class Player {
private:
	using Cords = std::pair<int, int>;
	std::vector <char> map_shot;//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count=10;		//Количество оставшихся кораблей
	bool move=false;
public:
	explicit Player(size_t pol_count);
	//Размещение корабля на карте
	bool setShip(Cords c, int _dir, int _deck);
	//Проверка пересечения кораблей
	bool isIntersecShip(Cords& c, int& _dir, int& _deck) noexcept;
	//Проверка выстрела
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr, int& pol_count);
	//Проверка попадания
	bool getShot(Cords& crd);
	//Проверка наличия кораблей
	int ShipCount()const { return ship_count; };
	//Передача карты игрока для печати
	std::vector<char>& getMap() { return map_shot; }
	//Проверка свободных клеток для хода
	//Проверка хода
	bool isMove() { return move; }
	//Для проверки работы
	void print();

	//Массив периметра корабля
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/

	

	
};

	

	
