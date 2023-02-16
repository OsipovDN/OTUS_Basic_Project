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
	std::vector <Cords> cord{};	//Массив координат корабля
	int hp;	//Убит или нет

public:
	Ship(Cords crd, int _dir, int _deck);
	//Проверка на убит или нет
	bool Islife()const noexcept;
	//Проверка попадания
	bool IsHit(const Cords& crd);
	//Возврат координат корабля
	std::vector <Cords> getCord()const noexcept { return cord; }
	//Возвращает количество жизней
	int hps() { return hp; }
};