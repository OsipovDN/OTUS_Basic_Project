#include "Ship.h"
#include <algorithm>
#include <iostream>



Ship::Ship(Cords crd, int _dir, int _deck) :hp(_deck) {
	cord.reserve(hp);
	if (_dir == UP || _dir == DOWN) {
		if (_dir == UP) {
			for (int i = crd.second; i > (crd.second - _deck); --i)
				cord.emplace_back(std::make_pair(crd.first,i ));
		}
		else {
			for (int i = crd.second; i < (crd.second + _deck); ++i)
				cord.emplace_back(std::make_pair(crd.first, i));
		}
	}
	else {
		if (_dir == RIGHT) {
			for (int i = crd.first; i < (crd.first + _deck); ++i)
				cord.emplace_back(std::make_pair(i, crd.second));
		}
		else {
			for (int i = crd.first; i > (crd.first - _deck); --i)
				cord.emplace_back(std::make_pair(i, crd.second));
		}
	}

};

bool Ship::Islife()const noexcept {
	return hp;
}
bool Ship::IsHit(const Cords& crd) {
	bool flag = false;
	std::for_each(cord.cbegin(), cord.cend(), [&](Cords p)mutable {
		if (p.first == crd.first && p.second == crd.second) {
			flag = true;
			hp--;
		}
		});
	return flag;
}