#include <Ship.h>
#include <iostream>
#include <algorithm>
#include <execution>


explicit Player::Player(int count) :ship_count(count) {
	navy.reserve(ship_count);
}

bool Player::setShip(int _x, int _y, int _dir, int _deck) {
	bool flag = intersecShip(_x, _y, _dir, _deck);
	if (flag) {
		std::cout << "Есть пересечение с лругим кораблем! Попробуйте снова." << std::endl;
		return false;
	}
	navy.emplace_back(Ship(_x, _y, _dir, _deck));
	return true;
}

bool Player::intersecShip(int& _x, int& _y, int& _dir, int& _deck) noexcept {
	bool flag = false;
	Ship temp{ _x,_y,_dir,_deck };
	auto temp_vec = temp.getCord();
	std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship s) {
		auto compar = s.getCord();
		for (const auto it : temp_vec) {
			for (const auto it_compar : compar) {
				if (it.first == it_compar.first && it.second == it_compar.second)
					flag = true;
			}
		}
		});
	return flag;
}

bool Player::getShot(int& _x, int& _y) {
	bool flag = false;
	std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship s)mutable {
		flag = s.IsHit(_x, _y);
		if (!s.Islife())
			ship_count--;
		});
	return flag;
}

bool Player::setShot(Player& plr) {
	int x = 0, y = 0;
	int count = 0;
	std::cout << "Введите координаты (x ,y) через пробел: "
		<< std::endl;
	for (;;) {
		std::cout << "x,y: ";
		std::cin >> x >> y;
		count = ((x - 1) * 10 + y) - 1;
		if (map_shot[count] != ' ') {
			std::cout << "По данной позиции ранее уже был сделан выстрел." <<
				std::endl;
			std::cout << "Повторите ввод." << std::endl;
			continue;
		}
		else {
			if (plr.getShot(x, y)) {
				map_shot[count] = 'X';
				continue;
			}
			else
				break;
		}
	}
	map_shot[count] = '+';
	return false;
}
