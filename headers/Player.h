#pragma once
#include <array>
#include <Ship.h>


class Player {
private:
	std::array <bool,10> ship_map;		//����� ����������� ��������
	std::array <bool,10> shot_map;		//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	//����������� (������������ )
	//�������� �� ������� �������� (���� ����- ��������)
	//���������� ������� �� �����
	//�������� �������� (��������� ����� ������ ����)
	//int getShipCount ()const;		���������� ���������� ���������� ��������
	//bool getMapCount (int x,int y)	�������� ���������

};
