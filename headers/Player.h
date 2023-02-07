#pragma once
#include <vector>
#include <array>


class Player {
private:
	std::array <char, 100> map_shot{};//����� ��������� ��������� (����� ���������?)
	std::vector<Ship> navy;
	int ship_count;		//���������� ���������� ��������
public:
	explicit Player(int count);
	//���������� ������� �� �����
	bool setShip(int _x, int _y, int _dir, int _deck);
	//�������� ����������� ��������
	bool intersecShip(int& _x, int& _y, int& _dir, int& _deck) noexcept;
	//�������� ���������
	bool getShot(int& _x, int& _y);
	//�������� �������� (��������� ����� ������ ����)
	bool setShot(Player& plr);
	//�������� ������� ��������
	bool ShipCount()const {return ship_count;};

	//������ ��������� �������
	/*std::vector <std::pair<int, int>>&& shipPer(int& _x, int& _y, int& _dir, int& _deck) {
		Ship temp(int& _x, int& _y, int& _dir, int& _deck);
		auto temp_vec = temp.getCord();
	}*/
};
