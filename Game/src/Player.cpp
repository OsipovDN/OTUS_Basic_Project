#include "Player.h"
#include "Ship.h"
#include <iostream>
#include <algorithm>
#include <execution>

Player::Player(const size_t& pol_count) {
	size_t pol_size = pol_count * pol_count;
	map_shot.reserve(pol_size);
	navy.reserve(ship_count);
	for (size_t i = 0; i < pol_size; ++i) {
		map_shot.emplace_back(static_cast <char>(149));
	}
};

bool Player::setShip(const Cords& crd, const int& _dir, const int& _deck)noexcept {
	bool flag = isIntersecShip(crd, _dir, _deck);
	if (!flag)
		return false;
	navy.emplace_back(Ship(crd, _dir, _deck));
	return true;
};

std::unique_ptr<Player>&& Player::setShot(std::unique_ptr<Player>&& plr, Cords& crd, const int& pol)noexcept {
	int count = 0;
	count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
	if (plr->getShot(crd)) {
		map_shot[count] = 'X';
		move = true;
	}
	else {
		map_shot[count] = '+';
		move = false;
	}
	return std::move(plr);
};

bool Player::getShot(Cords& crd) {
	bool flag = false;
	int temp = ship_count;
	std::for_each(std::execution::par, navy.begin(), navy.end(), [&](Ship& s)mutable {
		if (s.IsHit(crd)) {
			flag = true;
			if (!s.Islife())
				ship_count--;
		}
		});
	if (flag) {
		if (temp == ship_count) {
			system("cls");
			std::cout << "Попал!" << std::endl;
			return flag;
		}
		else {
			system("cls");
			std::cout << "Убит!" << std::endl;
			return flag;
		}
	}
	else {
		system("cls");
		std::cout << "Промах!" << std::endl;
		return flag;
	}

};

bool Player::isIntersecShip(const Cords& crd, const int& _dir, const int& _deck)const noexcept {
	bool flag = true;
	Ship temp{ crd,_dir,_deck };
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
};

bool Player::isRepeat(Cords& crd, int pol)const noexcept {
	int pos = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
	if (map_shot[pos] == 'X' || map_shot[pos] == '+')
		return true;
	else
		return false;
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



