#pragma once
#include "Player.h"
#include "Ship.h"

class Game {
private:
	Player plr1;
	Player plr2;
	bool gm_over;	//�������� ����� ����
public:

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
	/*�����������(����������� ������� ����������� ��������,
	// (���� ��� ������ �����), ����������� �������� ����������)*/

	//�������
	
	//�������� ������ �� ������� ���� � ����������� ��� �����������
	//�������� ������ �� ������� ���� ��� ��������
	//�������� ���������� ��������
	//�������� ������� ��������
	//����������� ��������


};
