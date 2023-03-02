#pragma once
#include <vector>

enum dir {
	UP = 1,
	RIGHT,
	DOWN,
	LEFT
};

class Ship {
private:

	using Cords = std::pair<int, int>;
	std::vector <Cords> cord;	//������ ��������� �������
	int hp;	//���� ��� ���

public:
	Ship(const Cords& crd, const int& _dir, const int& _deck);
	//�������� ���������
	bool isHit(Cords& crd)noexcept;
	//�������� �� ���� ��� ���
	bool isLife()const noexcept { return hp; };
	//������� ��������� �������
	std::vector <Cords> getCord()const noexcept { return cord; }
};