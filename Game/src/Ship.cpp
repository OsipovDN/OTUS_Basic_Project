#include "Ship.h"
#include <iostream>
#include <algorithm>
#include <execution>

Ship::Ship(const Cords& crd, const int& _dir, const int& _deck) :hp(_deck) {
	cord.reserve(hp);
	if (_dir == UP || _dir == DOWN) {
		if (_dir == UP) {
			for (int i = crd.second; i > (crd.second - _deck); --i)
				cord.emplace_back(std::make_pair(crd.first, i));
		}
		else {
			for (int i = crd.second; i < (crd.second + _deck); ++i)
				cord.emplace_back(std::make_pair(crd.first, i));
		}
	}
	else if (_dir == RIGHT || _dir == LEFT) {
		if (_dir == RIGHT) {
			for (int i = crd.first; i < (crd.first + _deck); ++i)
				cord.emplace_back(std::make_pair(i, crd.second));
		}
		else {
			for (int i = crd.first; i > (crd.first - _deck); --i)
				cord.emplace_back(std::make_pair(i, crd.second));
		}
	}
	else {
		std::cerr << "Incorrect direction value" << std::endl;
		EXIT_SUCCESS;
	}

};

bool Ship::isHit(Cords& crd)noexcept {
	bool flag = false;
	std::for_each(std::execution::par, cord.cbegin(), cord.cend(), [&](Cords p)mutable {
		if (p.first == crd.first && p.second == crd.second) {
			flag = true;
			hp--;
		}
		});
	return flag;
};