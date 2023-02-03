#pragma once
#include <utility>
#include <functional>
#include <vector>
#include <algorithm>

using Cords = std::pair<int, int>;

class Ship {
private:
	std::vector <Cords> cord;
	int dir;	//����������� ������������
	int hp;	//���� ��� ���
public:
	Ship(int& _x, int& _y, int& _dir, int& _deck):dir(_dir),hp(_deck) {
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

	//�������� �� ���� ��� ���
	bool Islife()const noexcept {
		return (hp==0)?false: true;
	}
	//�������� ���������
	bool IsHit(const int& _x, const int& _y)noexcept  {
		bool flag=false;
		for_each(cord.cbegin(), cord.cend(), [&](Cords p) {
			if (p.first == _x && p.second == _y) {
				hp--;
				flag=true;
			}
			});
		if (this->Islife()) {
			std::cout << "�����!" << std::endl;
			return flag;
		}
		else{
			std::cout << "����!" << std::endl;
			return flag;
		}
		std::cout << "������!" << std::endl;
			return flag;
	}

	const std::vector <Cords>& getCord()const {return cord;}

};