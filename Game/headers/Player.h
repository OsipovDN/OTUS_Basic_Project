#pragma once
#include "Ship.h"

class Player {
private:
	using Cords = std::pair<int, int>;
	std::vector <char> map_shot;//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count;		//Количество оставшихся кораблей
	bool move = false;
public:
	explicit Player(const size_t& pol_count);
	//Размещение корабля на карте
	bool setShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//Проверка попадания
	bool getShot(Cords& crd);
	//Проверка пересечения кораблей
	bool isIntersecShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//Проверка пересечения по периметру корабля
	std::vector<Ship> shipPerim(Cords crd, const int& _dir, const int& _deck);
	//Проверка повторного хода
	bool isRepeat(Cords& crd, size_t pol)const noexcept;
	//Задает метку на карте для каждого игрока
	void setPoint(Cords& crd, size_t pol, char& point)noexcept;
	//Возвращает количество кораблей
	int shipCount() const noexcept { return ship_count; };
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

	

	
	

	
};




