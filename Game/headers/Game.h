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
	inline int autoSet(int p)const;
	//�������� ������ �� ������� ����
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//�����  ������ �� �����
	void mapPol();
	//�������� ������� ��������
	bool isOver();
	//����������� �����
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//���� ���������
	Cords&& setMove(const std::unique_ptr<Player>& pl)const {
		Cords crd;
		int count = 0;
		for (;;) {
			//�������� ���������� ����
			std::cout << "������� ���������� (x ,y) ����� ������: "
				<< std::endl;
			std::cout << "x,y: ";
			std::cin >> crd.first >> crd.second;
			if (crd.first <= 0 || crd.second <= 0 || crd.first > pol || crd.second > pol) {
				system("cls");
				std::cout << "����� �� ������� ����! ���������� �����"
					<< std::endl;
				continue;
			}
			count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
			if (pl->isRepeat(crd,pol)) {
				system("cls");
				std::cout << "�� ������ ������� ����� ��� ��� ������ �������." <<
					std::endl;
				std::cout << "��������� ����." << std::endl;
				continue;
			}
			else
				return std::move (crd);
		}
	}
};

