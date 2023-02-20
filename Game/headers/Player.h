#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>


class Player {
private:
	using Cords = std::pair<int, int>;
	std::vector <char> map_shot;//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count=10;		//���������� ���������� ��������
	bool move=false;
public:
	explicit Player(size_t pol_count);
	//���������� ������� �� �����
	bool setShip(Cords c, int _dir, int _deck);
	//�������� ����������� ��������
	bool isIntersecShip(Cords& c, int& _dir, int& _deck) noexcept;
	//�������� ��������
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr,Cords& cord, int& pol_count);
	//�������� ���������
	bool getShot(Cords& crd);
	//�������� ������� ��������
	//�������� ���������� ����
	bool isRepeat(Cords& crd, int pol);
	int ShipCount()const { return ship_count; };
	//�������� ����� ������ ��� ������
	std::vector<char>& getMap() { return map_shot; }
	//�������� ����
	bool isMove() { return move; }
	//��� �������� ������
	void print();
	
	
};

	

	
