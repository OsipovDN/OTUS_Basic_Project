#pragma once
#include "Player.h"

//static enum direction{
//	UP=1,
//	RIGHT,
//	DOWN,
//	LEFT
//} dir;

class Game {
private:
	
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	int pol;		//������ �������� ����
	bool gm_over=false;	//�������� ����� ����
	bool input_mode=false;	//������ ����������� ��������
							//true-������, false- ��������������
	
public:
	//����������� (������ ������ ����������� � ������ ����)
	Game(bool m, int p=10);
	//������ ����������� ��������
	void manSetShip();
	// �������������� ����������� ��������
	std::unique_ptr<Player>&& autoSetShip(std::unique_ptr<Player>&& pl);
	//�������� ������ �� ������� ����
	bool testCords(int& _x, int& _y, int& _dir, int& _deck);
	//�������� ������� ��������
	bool isOver();
};
