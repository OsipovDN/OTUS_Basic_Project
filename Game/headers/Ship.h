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
	std::vector <Cords> cord{};	//������ ��������� �������
	int hp;	//���� ��� ���

public:
	Ship(Cords crd, int _dir, int _deck);
	//�������� �� ���� ��� ���
	bool Islife()const noexcept;
	//�������� ���������
	bool IsHit(const Cords& crd);
	//������� ��������� �������
	std::vector <Cords> getCord()const noexcept { return cord; }
	//���������� ���������� ������
	int hps() { return hp; }
};