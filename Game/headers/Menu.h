#pragma once
#include <iostream>

class Menu {
private:
	bool mult_plr;	//true- два игрока, false-один игрок
	bool auto_set_pl1;	//true- автоматическая расстановка, false- ручная
	bool auto_set_pl1;	//true- автоматическая расстановка, false- ручная

public:
	Menu() {};
	int mainMenu() {
		int val;
		std::cout << "\tГлавное меню" << std::endl;
		std::cout << "1. Играть\n2. Загрузить игру\n3. Выход\n-> ";
		while (val != 1 || val != 2 || val != 3) std::cin >> val;
		return val;
	};
	void setPlrVal() {
		int val;
		std::cout << "\tКоличество игроков:" << std::endl;
		std::cout << "1. Один\n2. Два\n3. Назад\n-> ";
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
