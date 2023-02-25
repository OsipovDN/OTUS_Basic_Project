#pragma once
#include "Player.h"
#include "Menu.h"
//#include <Windows.h>

class Game {
private:

	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	std::unique_ptr<Menu> menu;
	int pol;				//������ �������� ����
	//bool gm_over = false;	//�������� ����� ����
	bool multplr = false;		//true-��� ������, false- ���� �����
	

public:
	//����������� (������ ������ ����������� � ������ ����)
	Game();
	//������ ����
	void play();
	//������ ������ �������� ����
	void sizeOfTheField();
	//����� ����������� ��������
	void placementMode();
	//����������� �����
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//���� ���������
	Cords&& setMove(const std::unique_ptr<Player>& pl)const;
	//�������������� ������ ���������
	inline int autoSet(int p)const;
	//�������� ������ �� ������� ����
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//����� ������ �� �����
	void mapPol();
	//������ ���� ������
	std::vector<char>::const_iterator colorOutput(std::vector<char>::const_iterator it_begin);
	
};

