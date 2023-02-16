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
	bool gm_over = false;	//�������� ����� ����
	//bool input_navy = false;	//������ ����������� ��������
							//true-������, false- ��������������
	bool multplr=false;		//true-��� ������, false- ���� �����

public:
	//����������� (������ ������ ����������� � ������ ����)
	Game(int p = 10); 
	//������ ����
	void play();
	//�������������� ������ ���������
	int autoSet(int p) {
		int val = std::rand() % p + 1;
		return val;
	}
	//������ ����������� ��������
	//void manSetShip();
	// �������������� ����������� ��������
	//std::unique_ptr<Player>&& autoSetShip(std::unique_ptr<Player>&& pl);
	//�������� ������ �� ������� ����
	bool testCords(int& _x, int& _y, int& _dir, int& _deck);
	//����� ����� ������ �� �����
	void mapPol();
	//�������� ������� ��������
	bool isOver();

	void setNavy(std::unique_ptr<Player>& pl, bool st);
};

