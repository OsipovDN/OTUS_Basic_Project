#pragma once
#include <utility>
#include <functional>


class Ship {
private:
	//int x;		//���������� �� ��� �
	//int y;		//���������� �� ��� Y
	std::pair <int, int> cord;
	int dir;	//����������� ������������
	int deck;	//���������� �����
	int hp;	//���� ��� ���
public:
	Ship(int _x, int _y, int _deck, int _dir) :cord(std::make_pair(_x, _y)), deck(_deck), dir(_dir) {};
	//�������� �� ���� ��� ���
	bool life() {
		return hp;
	}
	//�������� ���������
	bool hit(int _x, int _y) {
		std::pair<int, int> shot = make pair(_x, _y);
		if (shot==)
	}

	
};