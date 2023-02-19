#include "Player.h"
#include "Ship.h"
#include <iostream>
#include <algorithm>
#include <execution>

Player::Player(size_t pol) {
	size_t pol_size = pol * pol;
	map_shot.reserve(pol_size);
	navy.reserve(ship_count);
	for (size_t i = 0; i < pol_size;++i) {
		map_shot.emplace_back(static_cast <char>(149));
	}
}

bool Player::setShip(Cords crd, int _dir, int _deck) {
	bool flag = isIntersecShip(crd, _dir, _deck);
	if (!flag)
		return false;
	navy.emplace_back(Ship(crd, _dir, _deck));
	return true;
}

bool Player::isIntersecShip(Cords& crd, int& _dir, int& _deck) noexcept {
	bool flag = true;
	Ship temp{ crd,_dir,_deck };
	auto temp_vec = temp.getCord();
	std::for_each(navy.cbegin(), navy.cend(), [&](Ship s) {
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

std::unique_ptr<Player>&& Player::setShot(std::unique_ptr<Player>&& plr,int& pol_count) {
	Cords crd;
	int count = 0;
	for (;;) {
		//Проверка сделанного хода
		std::cout << "Введите координаты (x ,y) через пробел: "
			<< std::endl;
		std::cout << "x,y: ";
		std::cin >> crd.first >> crd.second;
		if (crd.first <= 0 || crd.second <= 0 || crd.first > pol_count || crd.second > pol_count) {
			std::cout << "Выход за пределы поля! Попробуйте снова"
				<< std::endl;
			continue;
		}
		count = ((crd.second - 1) * static_cast<int>(pol_count) + crd.first) - 1;
		if (map_shot[count] != static_cast<char>(149)) {
			std::cout << "По данной позиции ранее уже был сделан выстрел." <<
				std::endl;
			std::cout << "Повторите ввод." << std::endl;
			continue;
		}
		else
			break;
	}
	if (plr->getShot(crd)) {
		map_shot[count] = 'X';
		move = true;
	}
	else {
		map_shot[count] = '+';
		move = false;
	}
	return std::move(plr);
}
//ДОРАБОТАТЬ
bool Player::getShot(Cords& crd) {
	bool flag = false;
	int temp = ship_count;
	std::for_each(navy.begin(), navy.end(), [&](Ship& s)mutable {
		if (s.IsHit(crd)) {
			flag = true;
			if (!s.Islife())
				ship_count--;
		}
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

void Player::print() {
	std::for_each(navy.cbegin(),navy.cend(), [](const Ship& p) {
		std::vector <Cords> obj = p.getCord();
		for (auto& it : obj) {
			std::cout << it.first << " " << it.second << std::endl;
		}
		std::cout << std::endl;
		});
	std::cout << std::endl;
}



