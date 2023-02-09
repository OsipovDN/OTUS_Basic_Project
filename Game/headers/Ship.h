#pragma once
#include <vector>

class Ship {
private:
	using Cords = std::pair<int, int>;

	std::vector <Cords> cord{};	//Массив координат корабля
	int hp;	//Убит или нет
public:
	Ship(int _x, int _y, int _dir, int _deck);
	//Проверка на убит или нет
	bool Islife()const noexcept;
	//Проверка попадания
	bool IsHit(const int& _x, const int& _y);
	//Возврат координат корабля
	std::vector <Cords> getCord()const noexcept {return cord;}
};