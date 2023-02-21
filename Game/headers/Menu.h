#pragma once
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif

class Menu {
private:

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	Menu() = default;
	int mainMenu() {
		int val;
		clrscr();
		for (;;) {
			std::cout << "\tГлавное меню" << std::endl;
			std::cout << "1. Играть\n3. Выход\n-> ";
			std::cin >> val;
			if (val != 1 && val != 3) {
				clrscr();
				std::cout << "Введено некорректное значение. Попробуйте еще раз!\n";
				continue;
			}
			else
				break;
		}
		clrscr();
		return val;
	};
	int setPlrVal() {
		int val;
		clrscr();
		for (;;) {
			std::cout << "\tКоличество игроков:" << std::endl;
			std::cout << "1. Один\n2. Два\n-> ";
			std::cin >> val;
			if (val != 1 && val != 2) {
				clrscr();
				std::cout << "Введено некорректное значение. Попробуйте еще раз!\n";
				continue;
			}
			else
				break;
		}
		return val;
	};

	int setPolVal() {
		int val;
		clrscr();
		for (;;) {
			std::cout << "\tВведите размер игрового поля (val x val)(min=10/max=30)." << std::endl;
			std::cout << "val-> ";
			std::cin >> val;
			if (val < 10 || val > 30 && !isdigit(val)) {
				clrscr();
				std::cout << "Введено некорректное значение. Попробуйте еще раз!\n";
				continue;
			}
			else
				break;
		}
		return val;
	}

	bool placement(int pl) {
		int val;
		clrscr();
		for (;;) {
			std::cout << "Игрок " << pl << std::endl;
			std::cout << "\tВведите способ расстановки флота" << std::endl;
			std::cout << "1. Ручной\n2. Автоматический\n-> ";
			std::cin >> val;
			if (val != 1 && val != 2) {
				clrscr();
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
	void clrscr() {
#ifdef _WIN32
		COORD tl = { 0,0 };
		CONSOLE_SCREEN_BUFFER_INFO s;
		GetConsoleScreenBufferInfo(console, &s);
		DWORD written, cells = s.dwSize.X * s.dwSize.Y;
		FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
		FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
		SetConsoleCursorPosition(console, tl);
#else
		std::cout << "\033[2J\033[1; 1H";
#endif
	};
	HANDLE& getHandle() {
		return console;
	}
	void chengeColor(WORD atr) {
		SetConsoleTextAttribute(console, atr);
	}
	void saveGame() {};
	void loadGame() {};

};
