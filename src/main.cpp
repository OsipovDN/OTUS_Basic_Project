#include <iostream>
#include "Player.h"
#include "Ship.h"
//int argc, char* argv[]
int main () {

	Ship A(7, 5, 1, 4);
	std::cout << std::endl;
	Ship B(7, 5, 2, 3);
	std::cout << std::endl;
	Ship C(7, 5, 3, 2);
	std::cout << std::endl;
	Ship D(7, 5, 4, 1);
	std::cout << A.IsHit(4, 5) << std::endl;
	std::cout << B.IsHit(8, 5) << std::endl;
	std::cout << B.IsHit(7, 3) << std::endl;

	return 0;
}