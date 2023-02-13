#include "Ship.h"
#include <algorithm>
#include <iostream>

Ship::Ship(int _x, int _y, int _dir, int _deck) :hp(_deck) {
	cord.reserve(hp);
	if (_dir == 1 || _dir == 3) {
		if (_dir == 1) {
			for (int i = _x; i > (_x - _deck); --i)
				cord.emplace_back(std::make_pair(i, _y));
		}
		else {
			for (int i = _x; i < (_x + _deck); ++i)
				cord.emplace_back(std::make_pair(i, _y));
		}
	}
	else {
		if (_dir == 2) {
			for (int i = _y; i < (_y + _deck); ++i)
				cord.emplace_back(std::make_pair(_x, i));
		}
		else {
			for (int i = _y; i > (_y - _deck); --i)
				cord.emplace_back(std::make_pair(_x, i));
		}
	}

};

bool Ship::Islife()const noexcept {
	return hp != 0;
}
bool Ship::IsHit(const int& _x, const int& _y) {
	bool flag = false;
	std::for_each(cord.cbegin(), cord.cend(), [&](Cords p) {
		if (p.first == _x && p.second == _y) {
			hp--;
			flag = true;
		}
		});
	return flag;
	/*if (flag) {
		if (this->Islife()) {
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
	}*/
}