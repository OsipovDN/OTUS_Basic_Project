#pragma once
#include <vector>
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
	//Проверка выстрела (повторный выбор одного поля)
	bool setShot(Player& plr);
	//Проверка наличия кораблей
	bool ShipCount()const {return ship_count;};

	//Массив периметра корабля
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/
};
