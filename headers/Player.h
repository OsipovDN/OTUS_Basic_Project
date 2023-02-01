#pragma once
#include <iostream>
//#include <iomanip>
#include <string>
#include <array>
#include <Ship.h>

static enum direction{
	UP=1,
	RIGHT,
	DOWN,
	LEFT
};

class Player {
private:
	std::array <bool, 100> shot_map{ false };		//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	Player(int count) :ship_count(count){
		navy.reserve(ship_count);
	}
	void setShip(int& _x, int& _y, int& _dir, int& _deck) {
		navy.emplace_back(Ship(_x, _y, _dir, _deck));
	}
	/*void shipInMap() {
		std::vector <std::pair<int, int >> temp;
		for ( const auto& it_navy : navy) {
			temp =it_navy.getCord();
			for (const auto& it_temp : temp) {
				shot_map [(it_temp.first-1)*10+it_temp.second]=true;
			}
		}
	}*/
	bool shot() {

	}

	//�������� �� ������� �������� (���� ����- ��������)
	//���������� ������� �� �����
	//�������� �������� (��������� ����� ������ ����)
	//int getShipCount ()const;		���������� ���������� ���������� ��������
	//bool getMapCount (int x,int y)	�������� ���������

};
