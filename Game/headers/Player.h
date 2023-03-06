#pragma once
#include "Ship.h"
#include <memory>
#include <iostream>

class Player {
private:
	using Cords = std::pair<int, int>;
	std::vector <char> map_shot;//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count = 10;		//Количество оставшихся кораблей
	bool move = false;
public:
	explicit Player(const size_t& pol_count);
	//Размещение корабля на карте
	bool setShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//Проверка попадания
	bool getShot(Cords& crd);
	//Проверка пересечения кораблей
	bool isIntersecShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//Проверка повторного хода
	bool isRepeat(Cords& crd, int pol)const noexcept;
	//Задает метку на карте для каждого игрока
	void setPoint(Cords& crd, size_t pol, char& point)noexcept;
	//Возвращает количество кораблей
	int ShipCount() const noexcept { return ship_count; };
	//Передача карты игрока для печати
	std::vector<char>& getMap()noexcept { return map_shot; }
	//Проверка хода
	bool isMove()const noexcept { return move; }
	//Возвращает вектор с коодинатами всех кораблей
	std::vector<Ship> getNavy()const noexcept { return navy; }
	//Задает статус хода
	void moveStat(bool m)noexcept { move = m; }
	//Для проверки работы
	void print()const;

	std::vector<Ship>&& shipPerim(Cords crd, const int& _dir, const int& _deck) {
		std::vector<Ship> temp;
		Cords temp_cords;
		Cords cords;
		int new_deck = _deck +2;
		temp.reserve(_deck);
		if (_dir == 1) {
			temp_cords = std::make_pair((crd.first - 1), crd.second+1);
			for (int i = 1; i <= 3; ++i) {
				temp.emplace_back(Ship(temp_cords, _dir, new_deck));
				cords = std::make_pair((temp_cords.first+1), temp_cords.second );
				temp_cords = cords;
			}
		}

		else if (_dir == 2) {
			temp_cords = std::make_pair((crd.first - 1), crd.second - 1);
			for (int i = 1; i <= 3; ++i) {
				temp.emplace_back(Ship(temp_cords, _dir, new_deck));
				cords = std::make_pair(temp_cords.first , (temp_cords.second + 1));
				temp_cords = cords;
			}
		}

		else if (_dir == 3) {
			temp_cords = std::make_pair((crd.first -1), crd.second - 1);
			for (int i = 1; i <= 3; ++i) {
				temp.emplace_back(Ship(temp_cords, _dir, new_deck));
				cords = std::make_pair((temp_cords.first + 1), temp_cords.second);
				temp_cords = cords;
			}
		}

		else if (_dir == 4) {
			temp_cords = std::make_pair((crd.first + 1), crd.second - 1);
			for (int i = 1; i <= 3; ++i) {
				temp.emplace_back(Ship(temp_cords, _dir, new_deck));
				cords = std::make_pair((temp_cords.first), (temp_cords.second + 1));
				temp_cords = cords;
			}
		}
		printTemp(temp);
		return std::move(temp);
	}

	void printTemp(std::vector<Ship>& obj_ship) {
		std::cout << std::endl << std::endl;
		for (const auto it : obj_ship) {
			auto temp = it.getCord();
			for (auto it_cord : temp) {
				std::cout << it_cord.first << " " << it_cord.second << "   ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;

	}
	
	

	
};




