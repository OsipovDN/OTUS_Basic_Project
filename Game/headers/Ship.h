#pragma once
#include <vector>

class Ship {
private:
	using Cords = std::pair<int, int>;

	std::vector <Cords> cord{};	//������ ��������� �������
	int hp;	//���� ��� ���
public:
	Ship(int _x, int _y, int _dir, int _deck);
	//�������� �� ���� ��� ���
	bool Islife()const noexcept;
	//�������� ���������
	bool IsHit(const int& _x, const int& _y);
	//������� ��������� �������
	std::vector <Cords> getCord()const noexcept {return cord;}
};