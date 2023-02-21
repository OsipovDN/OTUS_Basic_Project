#pragma once
#ifdef _WIN32
#include <Windows.h>
#endif

class Menu {
private:

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	Menu() = default;
	int mainMenu();
	int setPlrVal();
	int setPolVal();
	bool placement(int pl);
	void clrscr();
	HANDLE& getHandle() {return console;}
	void chengeColor(WORD atr) { SetConsoleTextAttribute(console, atr);}
	void saveGame() {};
	void loadGame() {};

};
