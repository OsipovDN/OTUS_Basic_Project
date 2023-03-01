#pragma once
#include "Ship.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>


TEST(Ship, InitializationObject) {

	std::pair <int, int> cords{ 5,4 };
	const int dir = 1;
	const int dec = 3;
	std::vector<std::pair<int, int>> res{ {5,4},{5,3},{5,2} };
	std::vector<std::pair<int, int>> expect;

	Ship obj(cords, dir, dec);
	expect = obj.getCord();

	EXPECT_EQ(res, expect);

}