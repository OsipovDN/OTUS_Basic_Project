#pragma once
#include "Player.h"
#include "Menu.h"

class Game {
private:

	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	std::unique_ptr<Menu> menu;
	int pol;				//������ �������� ����
	bool gm_over = false;	//�������� ����� ����
	bool multplr = false;		//true-��� ������, false- ���� �����

public:
	//����������� (������ ������ ����������� � ������ ����)
	Game();
	//������ ����
	void play();
	//����������� �����
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//���� ���������
	Cords&& setMove(const std::unique_ptr<Player>& pl)const;
	//�������������� ������ ���������
	inline int autoSet(int p)const;
	//�������� ������ �� ������� ����
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//�����  ������ �� �����
	void mapPol();
	//�������� ������� ��������
	bool isOver();


};

