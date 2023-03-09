#pragma once
#include "Ship.h"

class Player {
private:
	using Cords = std::pair<int, int>;
	std::vector <char> map_shot;//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
	bool move = false;
public:
	explicit Player(const size_t& pol_count);
	//���������� ������� �� �����
	bool setShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//�������� ���������
	bool getShot(Cords& crd);
	//�������� ����������� ��������
	bool isIntersecShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//�������� ����������� �� ��������� �������
	std::vector<Ship> shipPerim(Cords crd, const int& _dir, const int& _deck);
	//�������� ���������� ����
	bool isRepeat(Cords& crd, size_t pol)const noexcept;
	//������ ����� �� ����� ��� ������� ������
	void setPoint(Cords& crd, size_t pol, char& point)noexcept;
	//���������� ���������� ��������
	int shipCount() const noexcept { return ship_count; };
	//�������� ����� ������ ��� ������
	std::vector<char>& getMap()noexcept { return map_shot; }
	//�������� ����
	bool isMove()const noexcept { return move; }
	//���������� ������ � ����������� ���� ��������
	std::vector<Ship> getNavy()const noexcept { return navy; }
	//������ ������ ����
	void moveStat(bool m)noexcept { move = m; }
	//��� �������� ������
	void print()const;

	

	
	

	
};




