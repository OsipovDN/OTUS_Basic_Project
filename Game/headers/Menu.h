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
	void chengeColor(int atr);
	void saveGame() {};
	void loadGame() {};

};
