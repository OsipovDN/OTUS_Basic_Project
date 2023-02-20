#pragma once
#include "Ship.h"
#include <memory>

class Player {
private:
	using Cords = std::pair<int, int>;
	std::vector <char> map_shot;//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count = 10;		//���������� ���������� ��������
	bool move = false;
public:
	explicit Player(const size_t& pol_count);
	//���������� ������� �� �����
	bool setShip(const Cords& c, const int& _dir, const int& _deck)noexcept;
	//�������� ��������
	std::unique_ptr<Player>&& setShot(std::unique_ptr<Player>&& plr, Cords& cord, const int& pol_count)noexcept;
	//�������� ���������
	bool getShot(Cords& crd);
	//�������� ����������� ��������
	bool isIntersecShip(const Cords& c, const int& _dir, const int& _deck)const noexcept;
	//�������� ���������� ����
	bool isRepeat(Cords& crd, int pol)const noexcept;
	//���������� ���������� ��������
	int ShipCount() const noexcept { return ship_count; };
	//�������� ����� ������ ��� ������
	std::vector<char>& getMap() { return map_shot; }
	//�������� ����
	bool isMove()const noexcept { return move; }
	//��� �������� ������
	void print()const;

};




