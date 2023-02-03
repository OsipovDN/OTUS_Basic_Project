#pragma once
#include <iostream>
//#include <iomanip>
#include <string>
#include <array>
#include <algorithm>
#include <execution>
#include <Ship.h>


static enum direction{
	UP=1,
	RIGHT,
	DOWN,
	LEFT
};

class Player {
private:
	std::array <bool, 100> map_shot{};//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	Player(int count) :ship_count(count){
		navy.reserve(ship_count);
	}
	//���������� ������� �� �����
	//!!!!!!!
	void setShip(int& _x, int& _y, int& _dir, int& _deck) {
		navy.emplace_back(Ship(_x, _y, _dir, _deck));
	}
	//�������� ����������� ��������
	bool intersecShip(int& _x, int& _y, int& _dir, int& _deck) {
		if (_dir == 1 || _dir == 3) {
			if (_dir == 1) {
				
			}
			else {}
		}
		else {
			if (_dir == 2) {

			}
		}
	}

	//�������� ���������
	bool getShot(int& _x,int& _y) {
		bool flag=false;
		std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship& s) {
			flag = s.IsHit(_x, _y); 
			if (!s.Islife())
				ship_count--;
			});
		return flag;
	}

	//�������� �������� (��������� ����� ������ ����)
	bool setShot(Player& plr) {
		int x=0, y=0;
		int count=0;
		std::cout << "������� ���������� (x ,y) ����� ������: "
			<< std::endl;
		for (;;) {
			std::cout << "x,y: ";
			std::cin >> x >> y;
			count = ((x - 1) * 10 + y) - 1;
			if (map_shot[count]) {
				std::cout << "�� ������ ������� ����� ��� ��� ������ �������." <<
					std::endl;
				std::cout << "��������� ����." << std::endl;
				continue;
			}
			else {
				if (plr.getShot(x, y)) {
					map_shot[count] = true;
					continue;
				}
				else 
					break;
			}
		}
		map_shot[count] = true;
		return true;
		return false;
	}
	
	//�������� ������� ��������
	bool ShipCount()const {
		return ship_count;
	};
};
