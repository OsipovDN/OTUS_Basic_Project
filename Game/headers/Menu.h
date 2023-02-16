#pragma once
#include <iostream>

class Menu {
private:
	bool mult_plr;	//true- два игрока, false-один игрок
	bool auto_set_pl1;	//true- автоматическая расстановка, false- ручная
	bool auto_set_pl2;	//true- автоматическая расстановка, false- ручная

public:
	Menu() {};
	int mainMenu() {
		int val;
		system("cls");
		for (;;) {
			std::cout << "\tГлавное меню" << std::endl;
			std::cout << "1. Играть\n3. Выход\n-> ";
			std::cin >> val;
			if (val != 1 && val != 3) {
				system("cls");
				std::cout << "Введено некорректное значение. Попробуйте еще раз!\n";
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
			std::cout << "\tКоличество игроков:" << std::endl;
			std::cout << "1. Один\n2. Два\n-> ";
			std::cin >> val;
			if (val != 1 && val != 2) {
				system("cls");
				std::cout << "Введено некорректное значение. Попробуйте еще раз!\n";
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
			std::cout << "Игрок " << pl << std::endl;
			std::cout << "\tВведите способ расстановки флота" << std::endl;
			std::cout << "1. Ручной\n2. Автоматический\n-> ";
			std::cin >> val;
			if (val != 1 && val != 2) {
				system("cls");
				std::cout << "Введено некорректное значение. Попробуйте еще раз!";
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
