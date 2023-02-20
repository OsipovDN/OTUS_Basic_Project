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
	explicit Player(const size_t& pol_count);
	//Размещение корабля на карте
	bool setShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//Проверка пересечения кораблей
	bool isIntersecShip(const Cords& c, const int& _dir, const int& _deck)const noexcept;
	//Проверка выстрела
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr,Cords& cord, const int& pol_count)noexcept;
	//Проверка попадания
	bool getShot(Cords& crd);
	//Проверка повторного хода
	bool isRepeat(Cords& crd, int pol)const noexcept;
	//Возвращает количество кораблей
	int ShipCount() const noexcept { return ship_count; };
	//Передача карты игрока для печати
	std::vector<char>& getMap() { return map_shot; }
	//Проверка хода
	bool isMove()const noexcept { return move; }
	//Для проверки работы
	void print()const;
	
	
};

	

	
