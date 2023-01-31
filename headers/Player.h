#pragma once
#include <array>
#include <Ship.h>


class Player {
private:
	std::array <bool,100> shot_map;		//Карта сделанных выстрелов (Карта соперника?)
	std::vector<Ship> navy;
	int ship_count;		//Количество оставшихся кораблей
public:
	Player ()
	//Конструктор (Производится )
	//Проверка на наличие кораблей (если ноль- проиграл)
	//Размещение корабля на карте
	//Проверка выстрела (повторный выбор одного поля)
	//int getShipCount ()const;		Возвращает количество оставшихся кораблей
	//bool getMapCount (int x,int y)	Проверка попадания

};
