#pragma once
#include <utility>
#include <functional>
#include <vector>
#include <algorithm>


//class Ship {
//private:
//	//int x;		//координата по оси Х
//	//int y;		//координата по оси Y
//	std::pair <int, int> cord;
//	int dir;	//Направление расположения
//	int deck;	//Количество палуб
//	int hp;	//Убит или нет
//public:
//	Ship(int _x, int _y, int _dir, int _deck) :cord(std::make_pair(_x, _y)), dir(_dir), deck(_deck) {};
//	//Проверка на убит или нет
//	bool Islife() {
//		return hp;
//	}
//	//Проверка попадания
//	bool IsHit(int _x, int _y) {
//		//Проверка попадания если корабль в вертикальном положении
//		if (dir == 1 || dir == 3) {
//			if (cord.second != _y)
//				return false;
//			if (dir == 1) {
//				for (int i = cord.first; i< (cord.first - deck); --i) {
//					if (i == _x) {
//						hp--;
//						return true;
//					}
//				}
//				return false;
//			}
//			if (dir == 3) {
//				for (int i = cord.first; i < (cord.first + deck); ++i) {
//					if (i == _x) {
//						hp--;
//						return true;
//					}
//				}
//				return false;
//			}
//		}
//		//Проверка попадания если корабль в горизонтальном положении
//		if (dir == 2 || dir == 4) {
//			if (cord.first != _x)
//				return false;
//			if (dir == 2) {
//				for (int i = cord.second; i < (cord.second + deck); ++i) {
//					if (i == _y) {
//						hp--;
//						return true;
//					}
//				}
//				return false;
//			}
//			if (dir == 4) {
//				for (int i = cord.second; i < (cord.second - deck); --i) {
//					if (i == _y) {
//						hp--;
//						return true;
//					}
//				}
//				return false;
//			}
//		}
//	}
//
//	
//};
using Cords = std::pair<int, int>;
class Ship {
private:
	std::vector <Cords> cord;
	int dir;	//Направление расположения
	int deck;	//Количество палуб
	int hp;	//Убит или нет
public:
	Ship(int _x, int _y, int _dir, int _deck):dir(_dir),deck(_deck),hp(_deck) {
		cord.reserve(hp);
		if (dir == 1 || dir == 3) {
			if (dir == 1) {
				for (int i = _x; i > (_x - _deck); --i) 
					cord.emplace_back(std::make_pair(i, _y));
			}
			else {
				for (int i = _x; i < (_x + _deck); ++i)
					cord.emplace_back(std::make_pair(i, _y));
			}
		}
		else {
			if (dir == 2) {
				for (int i = _y; i < (_y + _deck); ++i)
					cord.emplace_back(std::make_pair(_x, i));
			}
			else {
				for (int i = _y; i > (_y - _deck); --i)
					cord.emplace_back(std::make_pair(_x, i));
			}
		}
		std::for_each(cord.cbegin(), cord.cend(), [](const Cords& p) {
			std::cout << p.first << " " << p.second << std::endl; });
	};

	//Проверка на убит или нет
	bool Islife() {
		return hp;
	}
	//Проверка попадания
	bool IsHit(int _x, int _y) {
		bool flag=false;
		//Проверка попадания если корабль в вертикальном положении
		for_each(cord.cbegin(), cord.cend(), [&](Cords p) {
			if (p.first == _x && p.second == _y) {
				hp--;
				flag = true;
			}
			});
			return flag;
	}


};