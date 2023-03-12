#include "Player.h"
#include <iostream>
#include <algorithm>
#include <execution>
#include <memory>


Player::Player(const size_t& pol_count):Player(){
	setSizePol(pol_count);
	setNavyPl(ship_count);
};

bool Player::setShip(const Cords& crd, const int& _dir, const int& _deck)noexcept {
	bool flag = isIntersecShip(crd, _dir, _deck);
	if (flag)
		return false;
	else {
		navy.emplace_back(Ship(crd, _dir, _deck));
		ship_count++;
		return true;
	}
};

bool Player::getShot(Cords& crd) {
	bool flag = false;
	int temp = ship_count;
	std::for_each(std::execution::par, navy.begin(), navy.end(), [&](Ship& s)mutable {
		if (s.isHit(crd)) {
			flag = true;
			if (!s.isLife())
				ship_count--;
		}
		});
	if (flag) {
		if (temp == ship_count) {
			std::cout << "Hit!" << std::endl;
			return flag;
		}
		else {
			std::cout << "Dead!" << std::endl;
			return flag;
		}
	}
	else {
		std::cout << "Missed!" << std::endl;
		return flag;
	}

};

bool Player::isIntersecShip(const Cords& crd, const int& _dir, const int& _deck) noexcept {
	bool flag = false;
	std::vector<Ship> obj_ship;
	obj_ship = shipPerim(crd, _dir, _deck);
	std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship s) {
		auto compar = s.getCord();
		for (const auto it : compar) {
			for (const auto it_obj_ship : obj_ship) {
				auto compar_obj_ship = it_obj_ship.getCord();
				for (const auto it_cords : compar_obj_ship) {
					if (it_cords.first == it.first && it_cords.second == it.second)
						flag = true;
				}
			}
		}
		});
	return flag;
};

std::vector<Ship>  Player::shipPerim(Cords crd, const int& _dir, const int& _deck) {
	std::vector<Ship> temp;
	Cords temp_cords;
	Cords cords;
	int new_deck = _deck + 2;
	temp.reserve(_deck);
	if (_dir == 1) {
		temp_cords = std::make_pair((crd.first - 1), crd.second + 1);
		for (int i = 1; i <= 3; ++i) {
			temp.emplace_back(Ship(temp_cords, _dir, new_deck));
			cords = std::make_pair((temp_cords.first + 1), temp_cords.second);
			temp_cords = cords;
		}
	}

	else if (_dir == 2) {
		temp_cords = std::make_pair((crd.first - 1), crd.second - 1);
		for (int i = 1; i <= 3; ++i) {
			temp.emplace_back(Ship(temp_cords, _dir, new_deck));
			cords = std::make_pair(temp_cords.first, (temp_cords.second + 1));
			temp_cords = cords;
		}
	}

	else if (_dir == 3) {
		temp_cords = std::make_pair((crd.first - 1), crd.second - 1);
		for (int i = 1; i <= 3; ++i) {
			temp.emplace_back(Ship(temp_cords, _dir, new_deck));
			cords = std::make_pair((temp_cords.first + 1), temp_cords.second);
			temp_cords = cords;
		}
	}

	else if (_dir == 4) {
		temp_cords = std::make_pair((crd.first + 1), crd.second - 1);
		for (int i = 1; i <= 3; ++i) {
			temp.emplace_back(Ship(temp_cords, _dir, new_deck));
			cords = std::make_pair((temp_cords.first), (temp_cords.second + 1));
			temp_cords = cords;
		}
	}
	return temp;
};

bool Player::isRepeat(Cords& crd, size_t pol)const noexcept {
	int pos = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
	if (map_shot[pos] == 'X' || map_shot[pos] == '+')
		return true;
	else
		return false;
};

void Player::setPoint(Cords& crd, size_t pol, char& point)noexcept {
	int count = 0;
	count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
	map_shot[count] = point;
};

void Player::setSizePol(size_t num) {
	size_t pol_size = num * num;
	map_shot.reserve(pol_size);
	for (size_t i = 0; i < pol_size; ++i) {
		map_shot.emplace_back(static_cast <char>(149));
	}
};

void Player::print()const {
	std::for_each(navy.cbegin(), navy.cend(), [](const Ship& p) {
		std::vector <Cords> obj = p.getCord();
		for (auto& it : obj) {
			std::cout << it.first << " " << it.second << std::endl;
		}
		std::cout << std::endl;
		});
	std::cout << std::endl;
};





