#include "Menu.h"
#include <iostream>

int Menu::mainMenu() {
	int v;
	clrscr();
	for (;;) {
		std::cout << "\tMain Menu" << std::endl;
		std::cout << "1. Play\n3. Exit\n-> ";
		std::cin >> v;
		if (std::cin.fail() || (v != 1 && v != 3)) {
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore();
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
	clrscr();
	return v;
};

void Menu::setPlrVal(int& v) {
	clrscr();
	for (;;) {
		std::cout << "\tNumber of players:" << std::endl;
		std::cout << "1. One\n2. Multiplayer\n-> ";
		std::cin >> v;
		if (std::cin.fail()||(v != 1 && v != 2) ) {
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore();
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
};

void Menu::setPolVal(int& p) {
	clrscr();
	for (;;) {
		std::cout << "\tEnter the size of the playing field (val x val)(min=10/max=30)." << std::endl;
		std::cout << "Size map-> ";
		std::cin >> p;
		if (std::cin.fail() || p < 10 || p > 30) {
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore();
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
};

bool Menu::placement(int pl) {
	int v;
	clrscr();
	for (;;) {
		std::cout << "Player " << pl << std::endl;
		std::cout << "\tEnter the placement method" << std::endl;
		std::cout << "1. Manual\n2. Auto\n-> ";
		std::cin >> v;
		if (std::cin.fail()||(v != 1 && v != 2)) {
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore();
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
	if (v == 1)
		return true;
	else
		return false;
};

void Menu::clrscr() {
#ifdef _WIN32
	/*COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);*/
	system("cls");
#else
	//std::cout << "\033[2J\033[1; 1H";
	system("clear");
#endif
};

void Menu::chengeColor(int atr) {
#ifdef _WIN32
	SetConsoleTextAttribute(console, static_cast <WORD>(atr));
#else
	if (atr == 4)
		printf("\x1b[31m");
	else if (atr == 10)
		printf("\x1b[32m");
	else
		printf("\x1b[37m");
#endif
}