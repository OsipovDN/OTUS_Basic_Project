#pragma once
#include "Player.h"
#include "Ship.h"

class Game {
private:
	Player plr1;
	Player plr2;
	bool gm_over;	//Проверка конца игры
	std::array <char, 100> map_pl1{};
	std::array <char, 100> map_pl2{};//Карта сделанных выстрелов (Карта соперника?)
public:
	//Проверка выстрела (повторный выбор одного поля)
	bool setShot(int& _x, int& _y) {
		int count = ((_x - 1) * 10 + _y) - 1;
		if (!shot_map[count]) {
			shot_map[count] = true;
			return true;
		}
		return false;
	}

	void ManSetShip() {
		int x = 0;
		int y = 0;
		std::string d;
		std::cout << "Ручной ввод расположения кораблей:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "Введите " << j << "-й " << i << "-й корабль: "
					<< std::endl;
				std::cout << "x= ";
				std::cin >> x;
				std::cout << "y= ";
				std::cin >> y;
				std::cout << "Направление (1-вверх,2-вправо,3-вниз,4-влево): ";

				navy.emplace_back(Ship(x, y, std::stoi(d), i));
			}
		}
	}
	/*Конструктор(определение способа расстановки кораблей,
	// (авто или ручной режим), расстановка кораблей противника)*/

	//выстрел
	
	//Проверка выхода за границу поля и пересечения при расстановке
	//Проверка выхода за границу поля при выстреле
	//Проверка повторного выстрела
	//Проверка наличия кораблей
	//Расстановка кораблей


};
