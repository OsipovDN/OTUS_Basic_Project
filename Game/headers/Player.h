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
	void setShot(Player& plr);
	//�������� ������� ��������
	bool ShipCount()const { return ship_count; };

	//������ ��������� �������
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/

	//��� �������� ������
	void print() {
		std::for_each(this->navy.cbegin(), this->navy.cend(), [](const Ship& p) {
			std::vector <std::pair<int, int>> obj = p.getCord();
			for (auto& it : obj) {
				std::cout << it.first << " " << it.second << std::endl;
			}
			std::cout << std::endl;
			});
		std::cout << std::endl;
	}

	void map() {
		int s = 0;
		for (auto it_map : map_shot) {
			if (s == 9) {
				std::cout << it_map << std::endl;
				s = 0;
			}
			else {
				std::cout << it_map << " ";
				s++;
			}
		}
	}

};

	

	
