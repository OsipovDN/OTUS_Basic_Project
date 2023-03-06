#pragma once
#include "Player.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>


struct PlayerFixture : public testing::Test {
	std::pair <int, int> cords{ 5,4 };
	std::vector<std::pair<int, int>> expect_cords{ {5,4},{5,3},{5,2} };
	size_t size_pol = 10;
	const int dir = 1;
	const int dec = 3;

	static void SetUpTestSuite() {}

	static void TearDownTestSuite() {}
	void SetUp() override {
		Player obj(size_pol);
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

TESTF(PlayerFixture, testSetShipMeth) {
	bool intersec_flag;
	bool shot_flag;
	std::pair<int, int> c;

	intersec_flag = obj.setShip(cords, dir, dec);

	EXPECT_FALSE(intersec_flag);
	for (int i = 0; i < 2; ++i) {
		shot_flag = false;
		c = { cords.first ,(cords.second - i) };
		shot_flag = obj.getShot(c);
		EXPECT_TRUE(shot_flag);
	}
}
