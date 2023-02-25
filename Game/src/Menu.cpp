#include "Menu.h"
#include <iostream>

int Menu::mainMenu() {
	int val;
	clrscr();
	for (;;) {
		std::cout << "\tMain Menu" << std::endl;
		std::cout << "1. Play\n3. Exit\n-> ";
		val=std::getchar()-'0';
		std::cin.ignore();
		if (val != 1 && val != 3) {
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
	clrscr();
	return val;
};

int Menu::setPlrVal() {
	int val;
	clrscr();
	for (;;) {
		std::cout << "\tNumber of players:" << std::endl;
		std::cout << "1. One\n2. Multiplayer\n-> ";
		val = std::getchar() - '0';
		std::cin.ignore();
		if (val != 1 && val != 2 ) {
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
	return val;
};

int Menu::setPolVal() {
	int val;
	clrscr();
	for (;;) {
		std::cout << "\tEnter the size of the playing field (val x val)(min=10/max=30)." << std::endl;
		std::cout << "Size map-> ";
		std::cin >> val;
		std::cin.ignore();
		if (val < 10 || val > 30) {
			clrscr();
			std::cout << val << std::endl;
			std::cout << "An incorrect value was entered. Try again!\n";
			continue;
		}
		else
			break;
	}
	return val;
};

bool Menu::placement(int pl) {
	int val;
	clrscr();
	for (;;) {
		std::cout << "Player " << pl << std::endl;
		std::cout << "\tEnter the placement method" << std::endl;
		std::cout << "1. Manual\n2. Auto\n-> ";
		val = std::getchar() - '0';
		std::cin.ignore();
		if (val != 1 && val != 2) {
			clrscr();
			std::cout << "An incorrect value was entered. Try again!\n";
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

void Menu::clrscr() {
#ifdef _WIN32
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
#else
	//std::cout << "\033[2J\033[1; 1H";
	system("clear");
#endif
};

void saveGame() {};
void loadGame() {};