#pragma once
#include <iostream>
#include <memory>
#include "Player.h"

//static enum direction{
//	UP=1,
//	RIGHT,
//	DOWN,
//	LEFT
//} dir;

class Game {
private:
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	bool gm_over=false;	//�������� ����� ����
public:
	//�����������
	explicit Game(int s=10) :plr1(std::make_unique<Player>(s)), 
		plr2(std::make_unique<Player>(s)) {};
	//������ ����������� 
	void ManSetShip() {
		int x = 0;
		int y = 0;
		std::string d;
		std::cout << "������ ���� ������������ ��������:"
			<< std::endl;
		for (int i = 4; i > 0; --i) {
			for (int j = 4; j >= i; --j) {
				std::cout << "������� " << j << "-� " << i << "-� �������: "
					<< std::endl;
				std::cout << "x= ";
				std::cin >> x;
				std::cout << "y= ";
				std::cin >> y;
				std::cout << "����������� (1-�����,2-������,3-����,4-�����): ";

				navy.emplace_back(Ship(x, y, std::stoi(d), i));
			}
		}
	}
	
	// (���� ��� ������ �����), ����������� �������� ����������)

	
	//�������� ������ �� ������� ����
	//�������� ������� ��������
	//����������� ��������


};
