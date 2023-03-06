#pragma once
#include "Player.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <vector>


struct PlayerFixture : public testing::Test {
	std::pair <int, int> cords{ 5,4 };
	std::vector<std::pair<int, int>> expect_cords{ {5,4},{5,3},{5,2} };
	size_t size_pol = 10;
	const int dir = 1;
	const int dec = 3;
	std::shared_ptr <Player>obj;

	static void SetUpTestSuite() {}

	static void TearDownTestSuite() {}
	void SetUp() override {
		obj=std::make_shared<Player>(size_pol);
	}
	void TearDown() override {}

};

TEST(Player, initializationPlayerObject) {
	size_t size_pol = 10;
	size_t size_pol_expect = 100;
	std::vector<char> map;

	Player obj(size_pol);
	map = obj.getMap();

	ASSERT_EQ(size_pol_expect, map.size());
	for (const auto& it : map) {
		ASSERT_EQ(it, static_cast <char>(149));
	}

}

TEST_F(PlayerFixture, testSetShipMeth) {
	bool intersec_flag;
	bool shot_flag;
	std::pair<int, int> c;

	//Проверка результата метода при введении первого корабля
	intersec_flag = obj->setShip(cords, dir, dec);
	EXPECT_TRUE(intersec_flag);
	//Проверка результата метода при введении второго корабля с такими же координатами
	intersec_flag = obj->setShip(cords, dir, dec);
	EXPECT_FALSE(intersec_flag);

	//Проверка координат введенного коробля
	for (int i = 0; i < 2; ++i) {
		shot_flag = false;
		c = { cords.first ,(cords.second - i) };
		shot_flag = obj->getShot(c);
		EXPECT_TRUE(shot_flag);
	}
}

TEST_F(PlayerFixture, testGetShotMethod) {
	bool shot_flag;
	std::pair <int, int > test_cords;

	obj->setShip(cords, dir, dec);

	shot_flag = obj->getShot(cords);
	ASSERT_TRUE(shot_flag);
	for (int i = 4; i <= 6; ++i) {
		for (int j = 2; j <= 4; ++j) {
			test_cords = { i, j };
			shot_flag = obj->getShot(test_cords);
			if (i == 5)
				ASSERT_TRUE(shot_flag);
			else
				ASSERT_FALSE(shot_flag);
		}
	}

}


