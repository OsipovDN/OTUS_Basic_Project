#pragma once
#include <array>
#include <Ship.h>


class Player {
private:
	std::array <bool,100> shot_map;		//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	Player ()
	//����������� (������������ )
	//�������� �� ������� �������� (���� ����- ��������)
	//���������� ������� �� �����
	//�������� �������� (��������� ����� ������ ����)
	//int getShipCount ()const;		���������� ���������� ���������� ��������
	//bool getMapCount (int x,int y)	�������� ���������

};
