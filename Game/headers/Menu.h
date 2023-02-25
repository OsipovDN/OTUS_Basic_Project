#pragma once
#ifdef _WIN32
#include <Windows.h>
#else
#include<cstdio>
#endif

class Menu {
private:
#ifdef _WIN32 
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	

public:
	Menu() = default;
	int mainMenu();
	void setPlrVal(int& v);
	void setPolVal(int& p);
	bool placement(int pl);
	void clrscr();
	//HANDLE& getHandle() {return console;}
	void chengeColor(int atr) { 
#ifdef _WIN32
		SetConsoleTextAttribute(console, static_cast <WORD>(atr));
#else
		if (atr==4)
			printf("\x1b[31m");
		else if (atr==10)
			printf("\x1b[32m");
		else
			printf("\x1b[37m");
#endif
	}
	void saveGame() {};
	void loadGame() {};

};
