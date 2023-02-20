#pragma once
#include "Player.h"
#include "Menu.h"

class Game {

private:
	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	int pol;		//������ �������� ����
	bool gm_over = false;	//�������� ����� ����
	//bool input_navy = false;	//������ ����������� ��������
							//true-������, false- ��������������
	bool multplr=false;		//true-��� ������, false- ���� �����

public:
	//����������� (������ ������ ����������� � ������ ����)
	Game(); 
	//������ ����
	void play();
	//�������������� ������ ���������
	int autoSet(int p);
	//�������� ������ �� ������� ����
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//�����  ������ �� �����
	void mapPol();
	//�������� ������� ��������
	bool isOver();
	//����������� �����
	void setNavy(std::unique_ptr<Player>& pl, bool st);
};

