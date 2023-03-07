#pragma once
#include "Player.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>


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
		obj = std::make_shared<Player>(size_pol);
		obj->setShip(cords, dir, dec);
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

TEST_F(PlayerFixture, testIsIntersecShip) {
	bool flag_res;
	std::pair<int, int> test_cords_perim{ 5,5 };
	std::pair<int, int> test_cords{ 5,6 };
	int dir_test;

	flag_res = obj->isIntersecShip(cords, dir, dec);
	ASSERT_TRUE(flag_res);
	dir_test = 2;
	flag_res = obj->isIntersecShip(test_cords_perim, dir_test, dec);
	ASSERT_TRUE(flag_res);
	dir_test = 4;
	flag_res = obj->isIntersecShip(test_cords, dir_test, dec);
	ASSERT_FALSE(flag_res);
}


TEST_F(PlayerFixture, testShipPerim) {
	std::pair<int, int> test_cord = { 4,5 };
	std::vector<Ship> res_vec_ship;
	std::vector<Ship> vec_ship_expect;
	int exp_num_cord = 15;
	int res_num_cord=0;

	int dec_test = dec + 2;
	for (int i = 0; i <= 2; ++i) {
		vec_ship_expect.emplace_back(Ship(test_cord, dir, dec_test));
		test_cord.first += 1;
	}

	res_vec_ship = obj->shipPerim(cords, dir, dec);


	std::for_each(vec_ship_expect.cbegin(), vec_ship_expect.cend(), [&](Ship exp) {
		auto exp_ship = exp.getCord();
		for (const auto it_exp_cord : exp_ship) {
			std::for_each(res_vec_ship.cbegin(), res_vec_ship.cend(), [&](Ship res) {
				auto res_ship = res.getCord();
				for (const auto it_res_cord : res_ship) {
					if (it_exp_cord.first == it_res_cord.first && it_exp_cord.second == it_res_cord.second)
						res_num_cord++;
				}});
		}});
	ASSERT_EQ(res_num_cord, exp_num_cord);
}