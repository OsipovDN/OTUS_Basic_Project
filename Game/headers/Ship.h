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
	bool IsHit(Cords& crd)noexcept;
	//�������� �� ���� ��� ���
	bool Islife()const noexcept { return hp; };
	//������� ��������� �������
	std::vector <Cords> getCord()const noexcept { return cord; }
};