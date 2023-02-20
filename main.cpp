#include <iostream>
#include "Game.h"

//int argc, char* argv[]
int main() {
	system("chcp 1251 >NUL");
	//ѕроверка класса корабль
	//–асстановка кораблей и проверка массива координат корабл¤
	/*Ship A(6, 5, 1, 4);
	std::cout << std::endl;
	Ship B(7, 5, 2, 3);
	std::cout << std::endl;
	Ship C(7, 5, 3, 2);
	std::cout << std::endl;
	Ship D(7, 5, 4, 1);
	std::cout << A.IsHit(4, 5) << std::endl;
	std::cout << B.IsHit(8, 5) << std::endl;
	std::cout << B.IsHit(7, 3) << std::endl;*/

	//ѕроверка класса игрок
	//ѕроверка пересечени¤ кораблей при расстановке
	/*Player Pl1{10};
	bool flag1 = false;
	bool flag2 = false;
	flag1 = Pl1.setShip(4, 2, 3, 4);
	flag2 = Pl1.setShip(6, 4, 4, 3);
	std::cout << flag1 << std::endl;
	std::cout << flag2 << std::endl;*/

	//ѕроверка автоматической расстановки кораблей
	Game Game{};
	Game.play();



	return 0;
}