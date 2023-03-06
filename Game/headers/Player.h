#pragma once
#include "Ship.h"
#include <memory>

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
	//Проверка выстрела
	//std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr, Cords& cord, const int& pol_count)noexcept;
	//Проверка попадания
	bool getShot(Cords& crd);
	//Проверка пересечения кораблей
	bool isIntersecShip(const Cords& c, const int& _dir, const int& _deck)const noexcept;
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




	std::vector<Ship> getNavy() { return navy; }

	void setPoint(Cords& crd, size_t pol, char point) {
		int count = 0;
		count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
		map_shot[count] = point;
	}

	void moveStat(bool m) { move = m; }
};




