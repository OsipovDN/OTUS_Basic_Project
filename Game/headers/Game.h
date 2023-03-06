#pragma once
#include "Player.h"
#include "Menu.h"
#include <iostream>
//#include <Windows.h>

class Game {
private:

	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	std::unique_ptr<Menu> menu;
	int pol = 10;				//������ �������� ����
	//bool gm_over = false;	//�������� ����� ����
	bool multplr = false;		//true-��� ������, false- ���� �����


public:
	//����������� (������ ������ ����������� � ������ ����)
	Game();
	//������ ����
	void play();
	//������ ���������� �������
	void numberOfPlayers();
	//������ ������ �������� ����
	void sizeOfTheField();
	//����� ����������� ��������
	void placementMode();
	//����������� �����
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//���� ���������
	Cords&& setMove(const std::unique_ptr<Player>& pl)const;
	//������� �������
	char setShot(const std::unique_ptr<Player>& pl1, const std::unique_ptr<Player>& pl2, Cords& crd)noexcept;
	//�������������� ������ ���������
	inline int autoSet(int& p)const;
	//�������� ������ �� ������� ����
	bool outOfBounds(Cords& crd, int& _dir, int& _deck)const noexcept;
	//����� ������ �� �����
	void mapPol();
	//������ ���� ������
	std::vector<char>::const_iterator colorOutput(std::vector<char>::const_iterator it_begin);



	
	

};

