#pragma once
#include <iostream>

class Menu {
private:
	bool mult_plr;	//true- ��� ������, false-���� �����
	bool auto_set_pl1;	//true- �������������� �����������, false- ������
	bool auto_set_pl2;	//true- �������������� �����������, false- ������

public:
	Menu() {};
	int mainMenu() {
		int val;
		system("cls");
		for (;;) {
			std::cout << "\t������� ����" << std::endl;
			std::cout << "1. ������\n3. �����\n-> ";
			std::cin >> val;
			if (val != 1 && val != 3) {
				system("cls");
				std::cout << "������� ������������ ��������. ���������� ��� ���!\n";
				continue;
			}
			else
				break;
		}
		return val;
	};
	int setPlrVal() {
		int val;
		system("cls");
		for (;;) {
			std::cout << "\t���������� �������:" << std::endl;
			std::cout << "1. ����\n2. ���\n-> ";
			std::cin >> val;
			if (val != 1 && val != 2) {
				system("cls");
				std::cout << "������� ������������ ��������. ���������� ��� ���!\n";
				continue;
			}
			else
				break;
		}
		return val;
	};

	bool placement(int pl) {
		int val;
		system("cls");
		for (;;) {
			std::cout << "����� " << pl << std::endl;
			std::cout << "\t������� ������ ����������� �����" << std::endl;
			std::cout << "1. ������\n2. ��������������\n-> ";
			std::cin >> val;
			if (val != 1 && val != 2) {
				system("cls");
				std::cout << "������� ������������ ��������. ���������� ��� ���!";
				continue;
			}
			else
				break;
		}
		if (val == 1)
			return true;
		else 
			return false;
	};
	void saveGame() {};
	void loadGame() {};
	
};
