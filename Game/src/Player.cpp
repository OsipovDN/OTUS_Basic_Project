#include "Player.h"
#include "Ship.h"
#include <iostream>
#include <algorithm>
#include <execution>

Player::Player(int count) :ship_count(count) {
	for (auto& it_map : map_shot) {
		it_map = static_cast <char>(149);
	}
	navy.reserve(ship_count);
}

bool Player::setShip(int _x, int _y, int _dir, int _deck) {
	bool flag = intersecShip(_x, _y, _dir, _deck);
	if (!flag)
		return false;
	navy.emplace_back(Ship(_x, _y, _dir, _deck));
	return true;
}

bool Player::intersecShip(int& _x, int& _y, int& _dir, int& _deck) noexcept {
	bool flag = true;
	Ship temp{ _x,_y,_dir,_deck };
	auto temp_vec = temp.getCord();
	std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship s) {
		auto compar = s.getCord();
		for (const auto it : temp_vec) {
			for (const auto it_compar : compar) {
				if (it.first == it_compar.first && it.second == it_compar.second)
					flag = false;
			}
		}
		});
	return flag;
}

bool Player::getShot(int& _x, int& _y) {
	bool flag = false;
	int temp = ship_count;
	std::for_each(navy.begin(), navy.end(), [&](Ship& s)mutable {
		if (s.IsHit(_x, _y))
			flag = true;
		if (!s.Islife())
			ship_count--;
		});
	if (flag) {
		if (temp== ship_count) {
			std::cout << "Попал!" << std::endl;
			return flag;
		}
		else {
			std::cout << "Убит!" << std::endl;
			return flag;
		}
	}
	else {
		std::cout << "Промах!" << std::endl;
		return flag;
	}
	
}

std::unique_ptr<Player>&& Player::setShot(std::unique_ptr<Player>&& plr ) {
	int x = 0, y = 0;
	int count = 0;
		for (;;) {
			std::cout << "Введите координаты (x ,y) через пробел: "
				<< std::endl;
			std::cout << "x,y: ";
			std::cin >> x >> y;
			count = ((y - 1) * 10 + x) - 1;
			if (map_shot[count] != static_cast<char>(149)) {
				std::cout << "По данной позиции ранее уже был сделан выстрел." <<
					std::endl;
				std::cout << "Повторите ввод." << std::endl;
				continue;
			}
			else
				break;
		}
		if (plr->getShot(x, y)) 
			map_shot[count] = 'X';
		else 
			map_shot[count] = '+';
		return std::move(plr);
}

void Player::print() {
	std::for_each(this->navy.cbegin(), this->navy.cend(), [](const Ship& p) {
		std::vector <std::pair<int, int>> obj = p.getCord();
		for (auto& it : obj) {
			std::cout << it.first << " " << it.second << std::endl;
		}
		std::cout << std::endl;
		});
	std::cout << std::endl;
}



