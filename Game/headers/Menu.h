#pragma once
#include <iostream>

class Menu {
private:
	bool mult_plr;	//true- ��� ������, false-���� �����
	bool auto_set_pl1;	//true- �������������� �����������, false- ������
	bool auto_set_pl1;	//true- �������������� �����������, false- ������

public:
	Menu() {};
	int mainMenu() {
		int val;
		std::cout << "\t������� ����" << std::endl;
		std::cout << "1. ������\n2. ��������� ����\n3. �����\n-> ";
		while (val != 1 || val != 2 || val != 3) std::cin >> val;
		return val;
	};
	void setPlrVal() {
		int val;
		std::cout << "\t���������� �������:" << std::endl;
		std::cout << "1. ����\n2. ���\n3. �����\n-> ";
		while (val != 1 || val != 2 || val != 3) std::cin >> val;
		if (val == 1)
			mult_plr = false;
		else if (val == 2)
			mult_plr = true;
		else
			mainMenu();
	};
	void saveGame() {};
	void loadGame() {};
	void setNavy() {};
};
