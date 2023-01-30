#pragma once
#include <utility>
#include <functional>


class Ship {
private:
	//int x;		//координата по оси Х
	//int y;		//координата по оси Y
	std::pair <int, int> cord;
	int dir;	//Направление расположения
	int deck;	//Количество палуб
	int hp;	//Убит или нет
public:
	Ship(int _x, int _y, int _deck, int _dir) :cord(std::make_pair(_x, _y)), deck(_deck), dir(_dir) {};
	//Проверка на убит или нет
	bool life() {
		return hp;
	}
	//Проверка попадания
	bool hit(int _x, int _y) {
		std::pair<int, int> shot = make pair(_x, _y);
		if (shot==)
	}

	
};