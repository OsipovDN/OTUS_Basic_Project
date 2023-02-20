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
	Ship(const Cords& crd, const int& _dir,const int& _deck);
	//�������� �� ���� ��� ���
	bool Islife()const noexcept;
	//�������� ���������
	bool IsHit( Cords& crd)noexcept;
	//������� ��������� �������
	std::vector <Cords> getCord()const noexcept { return cord; }
	//���������� ���������� ������
	int hps()const noexcept { return hp; }
};