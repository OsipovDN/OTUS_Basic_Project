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
	void setShot(Player& plr);
	//Проверка наличия кораблей
	bool ShipCount()const { return ship_count; };

	//Массив периметра корабля
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/

	//Для проверки работы
	void print() {
		std::for_each(this->navy.cbegin(), this->navy.cend(), [](const Ship& p) {
			std::vector <std::pair<int, int>> obj = p.getCord();
			for (auto& it : obj) {
				std::cout << it.first << " " << it.second << std::endl;
			}
			std::cout << std::endl;
			});
		std::cout << std::endl;
	}

	void map() {
		int s = 0;
		for (auto it_map : map_shot) {
			if (s == 9) {
				std::cout << it_map << std::endl;
				s = 0;
			}
			else {
				std::cout << it_map << " ";
				s++;
			}
		}
	}

};

	

	
