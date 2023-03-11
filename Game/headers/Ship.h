#pragma once
#include <vector>

enum dir {
	UP = 1,
	RIGHT,
	DOWN,
	LEFT
};

class Ship {
private:

	using Cords = std::pair<int, int>;
	std::vector <Cords> cord;	//Массив координат корабля
	int hp;	//Убит или нет

public:
	Ship(const Cords& crd, const int& _dir, const int& _deck);
	//Проверка попадания
	bool isHit(Cords& crd)noexcept;
	//Проверка на убит или нет
	bool isLife()const noexcept { return hp; };
	//Возврат координат корабля
	std::vector <Cords> getCord()const noexcept { return cord; }
};