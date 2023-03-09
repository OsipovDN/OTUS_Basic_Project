#pragma once
#include "Player.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>


struct PlayerFixture : public testing::Test {
	std::shared_ptr <Player>obj;
	std::pair <int, int> cords{ 5,4 };
	std::vector<std::pair<int, int>> expect_cords{ {5,4},{5,3},{5,2} };
	const int dir_up = 1,dir_right = 2, dir_down = 3, dir_left = 4;
	size_t size_pol = 10;
	const int dec = 3;

	static void SetUpTestSuite() {}

	static void TearDownTestSuite() {}
	void SetUp() override {
		obj = std::make_shared<Player>(size_pol);
		obj->setShip(cords, dir_up, dec);
	}
	void TearDown() override {}

};

TEST(Player, initializationPlayerObject) {
	std::cout << "Checking object initialization" << std::endl;
	size_t size_pol = 10;
	size_t size_pol_expect = 100;
	std::vector<char> map;

	Player obj(size_pol);
	map = obj.getMap();

	std::cout << "Checking the size of map" << std::endl;
	ASSERT_EQ(size_pol_expect, map.size());
	std::cout << "Checking map filling" << std::endl;
	for (const auto& it : map) {
		ASSERT_EQ(it, static_cast <char>(149));
	}

}

TEST_F(PlayerFixture, testSetShipMeth) {
	bool intersec_flag;
	bool shot_flag;
	std::pair<int, int> c;

	//�������� ���������� ������ ��� �������� ������� ������� � ������ �� ������������
	std::cout << "Checking the result when re-entering" << std::endl;
	intersec_flag = obj->setShip(cords, dir_up, dec);
	EXPECT_FALSE(intersec_flag);

	//�������� ��������� ���������� �������
	std::cout << "Checking the coordinates of the entered ship" << std::endl;
	for (int i = 0; i < 2; ++i) {
		shot_flag = false;
		c = { cords.first ,(cords.second - i) };
		shot_flag = obj->getShot(c);
		ASSERT_TRUE(shot_flag);
	}
}

TEST_F(PlayerFixture, testGetShotMeth) {
	bool shot_flag;
	std::pair <int, int > test_cords;

	shot_flag = obj->getShot(cords);

	std::cout << "Checking for getting into the ship" << std::endl;
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

TEST_F(PlayerFixture, testIsIntersecShipMeth) {
	bool flag_res;
	std::pair<int, int> test_cords_perim{ 5,5 };
	std::pair<int, int> test_cords{ 5,6 };

	std::cout << "Checking a guaranteed intersection" << std::endl;
	flag_res = obj->isIntersecShip(cords, dir_up, dec);
	ASSERT_TRUE(flag_res);
	flag_res = obj->isIntersecShip(test_cords_perim, dir_left, dec);
	ASSERT_TRUE(flag_res);
	std::cout << "Checking for the absence of an intersection" << std::endl;
	flag_res = obj->isIntersecShip(test_cords, dir_down, dec);
	ASSERT_FALSE(flag_res);
}


TEST_F(PlayerFixture, testShipPerimMeth) {
	std::pair<int, int> test_cord_up = { 4,5 };
	std::pair<int, int> test_cord_right = { 4,3 };
	std::pair<int, int> test_cord_down = { 4,3 };
	std::pair<int, int> test_cord_left = { 6,3 };
	std::vector<Ship> res_vec_ship_up, res_vec_ship_right, res_vec_ship_down, res_vec_ship_left;
	std::vector<Ship> expect_vec_ship_up, expect_vec_ship_right, expect_vec_ship_down, expect_vec_ship_left;
	int exp_num_cord = 15;
	int res_num_cord=0;
	int dec_test = dec + 2;


	for (int i = 0; i <= 2; ++i) {
		expect_vec_ship_up.emplace_back(Ship(test_cord_up, dir_up, dec_test));
		test_cord_up.first += 1;
	}
	for (int i = 0; i <= 2; ++i) {
		expect_vec_ship_right.emplace_back(Ship(test_cord_right, dir_right, dec_test));
		test_cord_right.second += 1;
	}
	for (int i = 0; i <= 2; ++i) {
		expect_vec_ship_down.emplace_back(Ship(test_cord_down, dir_down, dec_test));
		test_cord_down.first += 1;
	}
	for (int i = 0; i <= 2; ++i) {
		expect_vec_ship_left.emplace_back(Ship(test_cord_left, dir_left, dec_test));
		test_cord_left.second += 1;
	}

	res_vec_ship_up = obj->shipPerim(cords, dir_up, dec);
	res_vec_ship_right = obj->shipPerim(cords, dir_right, dec);
	res_vec_ship_down = obj->shipPerim(cords, dir_down, dec);
	res_vec_ship_left = obj->shipPerim(cords, dir_left, dec);

	std::cout << "Checking the perimeter of the ship in the up position" << std::endl;
	std::for_each(expect_vec_ship_up.cbegin(), expect_vec_ship_up.cend(), [&](Ship exp) {
		auto exp_ship = exp.getCord();
		for (const auto it_exp_cord : exp_ship) {
			std::for_each(res_vec_ship_up.cbegin(), res_vec_ship_up.cend(), [&](Ship res) {
				auto res_ship = res.getCord();
				for (const auto it_res_cord : res_ship) {
					if (it_exp_cord.first == it_res_cord.first && it_exp_cord.second == it_res_cord.second)
						res_num_cord++;
				}});
		}});
	ASSERT_EQ(res_num_cord, exp_num_cord);
	res_num_cord = 0;
	std::cout << "Checking the perimeter of the ship in the right position" << std::endl;
	std::for_each(expect_vec_ship_right.cbegin(), expect_vec_ship_right.cend(), [&](Ship exp) {
		auto exp_ship = exp.getCord();
		for (const auto it_exp_cord : exp_ship) {
			std::for_each(res_vec_ship_right.cbegin(), res_vec_ship_right.cend(), [&](Ship res) {
				auto res_ship = res.getCord();
				for (const auto it_res_cord : res_ship) {
					if (it_exp_cord.first == it_res_cord.first && it_exp_cord.second == it_res_cord.second)
						res_num_cord++;
				}});
		}});
	ASSERT_EQ(res_num_cord, exp_num_cord);
	res_num_cord = 0;
	std::cout << "Checking the perimeter of the ship in the down position" << std::endl;
	std::for_each(expect_vec_ship_down.cbegin(), expect_vec_ship_down.cend(), [&](Ship exp) {
		auto exp_ship = exp.getCord();
		for (const auto it_exp_cord : exp_ship) {
			std::for_each(res_vec_ship_down.cbegin(), res_vec_ship_down.cend(), [&](Ship res) {
				auto res_ship = res.getCord();
				for (const auto it_res_cord : res_ship) {
					if (it_exp_cord.first == it_res_cord.first && it_exp_cord.second == it_res_cord.second)
						res_num_cord++;
				}});
		}});
	ASSERT_EQ(res_num_cord, exp_num_cord);
	res_num_cord = 0;
	std::cout << "Checking the perimeter of the ship in the left position" << std::endl;
	std::for_each(expect_vec_ship_left.cbegin(), expect_vec_ship_left.cend(), [&](Ship exp) {
		auto exp_ship = exp.getCord();
		for (const auto it_exp_cord : exp_ship) {
			std::for_each(res_vec_ship_left.cbegin(), res_vec_ship_left.cend(), [&](Ship res) {
				auto res_ship = res.getCord();
				for (const auto it_res_cord : res_ship) {
					if (it_exp_cord.first == it_res_cord.first && it_exp_cord.second == it_res_cord.second)
						res_num_cord++;
				}});
		}});
	ASSERT_EQ(res_num_cord, exp_num_cord);
}

TEST_F(PlayerFixture, testIsRepeatMeth) {
	bool flag_repeat_res;
	char hit = 'X', mis = '+';

	std::cout << "Checking the first shot" << std::endl;
	flag_repeat_res = obj->isRepeat(cords, size_pol);
	ASSERT_FALSE(flag_repeat_res);

	std::cout << "Checking the re-run" << std::endl;
	obj->setPoint(cords,size_pol,hit);
	flag_repeat_res = obj->isRepeat(cords, size_pol);
	ASSERT_TRUE(flag_repeat_res);
	obj->setPoint(cords, size_pol, mis);
	flag_repeat_res = obj->isRepeat(cords, size_pol);
	ASSERT_TRUE(flag_repeat_res);
}

