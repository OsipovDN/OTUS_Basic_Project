#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>


class Player {
private:
	std::array <char, 100> map_shot{};//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	explicit Player(int count);
	//���������� ������� �� �����
	bool setShip(int _x, int _y, int _dir, int _deck);
	//�������� ����������� ��������
	bool intersecShip(int& _x, int& _y, int& _dir, int& _deck) noexcept;
	//�������� ���������
	bool getShot(int& _x, int& _y);
	//�������� ��������
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr);
	//�������� ������� ��������
	int ShipCount()const { return ship_count; };

	//������ ��������� �������
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/

	//��� �������� ������
	void print();

	std::array<char,100>* getMap() {
		return &map_shot;

	}
};

	

	
