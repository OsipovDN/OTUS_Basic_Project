#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <execution>
#include <Ship.h>


//static enum direction{
//	UP=1,
//	RIGHT,
//	DOWN,
//	LEFT
//} dir;

class Player {
private:
	std::array <char, 100> map_shot{};//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	Player(int count) :ship_count(count){
		navy.reserve(ship_count);
	}

	//���������� ������� �� �����
	bool setShip(int _x, int _y, int _dir, int _deck) {
		bool flag = intersecShip(_x, _y, _dir, _deck);
		if (flag) {
			std::cout << "���� ����������� � ������ ��������! ���������� �����." << std::endl;
			return false;
		}
		navy.emplace_back(Ship(_x, _y, _dir, _deck));
		return true;
	}
	//������ ��������� �������
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();	
	}*/

	//�������� ����������� ��������
	bool intersecShip(int& _x, int& _y, int& _dir, int& _deck) {
		bool flag = false;
		Ship temp{ _x,_y,_dir,_deck };
		auto temp_vec=temp.getCord();
		std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship s) {
			auto compar = s.getCord();
			for (const auto it : temp_vec) {
				for (const auto it_compar : compar) {
					if (it.first == it_compar.first && it.second == it_compar.second)
						flag = true;
				}
			}
			});
		return flag;
	}

	//�������� ���������
	bool getShot(int& _x,int& _y) {
		bool flag=false;
		std::for_each(std::execution::par, navy.cbegin(), navy.cend(), [&](Ship s)mutable {
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
			if (map_shot[count]!=' ') {
				std::cout << "�� ������ ������� ����� ��� ��� ������ �������." <<
					std::endl;
				std::cout << "��������� ����." << std::endl;
				continue;
			}
			else {
				if (plr.getShot(x, y)) {
					map_shot[count] = 'X';
					continue;
				}
				else 
					break;
			}
		}
		map_shot[count] = '+';
		return false;
	}
	
	//�������� ������� ��������
	bool ShipCount()const {
		return ship_count;
	};
};
