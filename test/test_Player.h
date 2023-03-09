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
	const int dir_up = 1, dir_right = 2, dir_down = 3, dir_left = 4;
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
	int expect_ship_count = 0,res_ship_count;

	Player obj(size_pol);
	map = obj.getMap();

	std::cout << "Checking the size of map" << std::endl;
	ASSERT_EQ(size_pol_expect, map.size());
	std::cout << "Checking map filling" << std::endl;
	for (const auto& it : map) {
		ASSERT_EQ(it, static_cast <char>(149));
	}
	std::cout << "Checking ship count" << std::endl;
	res_ship_count = obj.shipCount();
	ASSERT_EQ(res_ship_count, expect_ship_count);

}

TEST_F(PlayerFixture, testSetShipMeth) {
	bool intersec_flag;
	bool shot_flag;
	std::pair<int, int> c;

	//Проверка результата метода при введении второго корабля с такими же координатами
	std::cout << "Checking the result when re-entering" << std::endl;
	intersec_flag = obj->setShip(cords, dir_up, dec);
	EXPECT_FALSE(intersec_flag);

	//Проверка координат введенного коробля
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
	int res_num_cord = 0;
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
	obj->setPoint(cords, size_pol, hit);
	flag_repeat_res = obj->isRepeat(cords, size_pol);
	ASSERT_TRUE(flag_repeat_res);
	obj->setPoint(cords, size_pol, mis);
	flag_repeat_res = obj->isRepeat(cords, size_pol);
	ASSERT_TRUE(flag_repeat_res);
}

TEST_F(PlayerFixture, testSetPointMeth) {
	std::vector<char> res_map;
	int pos_in_map = ((cords.second - 1) * static_cast<int>(size_pol) + cords.first) - 1;
	char hit = 'X', mis = '+';
	int expect_count_pos = 1;
	std::vector<char>::iterator::difference_type count;

	std::cout << "Checking the pos value (hit)" << std::endl;
	obj->setPoint(cords, size_pol, hit);
	res_map = obj->getMap();
	ASSERT_EQ(res_map[pos_in_map], hit);

	std::cout << "Checking the number of relevant fields (hit)" << std::endl;
	count = count_if(res_map.cbegin(), res_map.cend(), [&](char sym){
		return (sym == hit) ? true : false; });
	ASSERT_EQ(expect_count_pos, count);

	std::cout << "Checking the pos value (mis)" << std::endl;
	obj->setPoint(cords, size_pol, mis);
	res_map = obj->getMap();
	ASSERT_EQ(res_map[pos_in_map], mis);

	std::cout << "Checking the number of relevant fields (mis)" << std::endl;
	count = count_if(res_map.cbegin(), res_map.cend(), [&](char sym) {
		return (sym == mis) ? true : false; });
	ASSERT_EQ(expect_count_pos, count);

}

TEST_F(PlayerFixture, testShipCountMeth) {
	int expect_ship_count = 1;
	int res_ship_count;

	res_ship_count = obj->shipCount();

	std::cout << "Checking the number of ships" << std::endl;
	ASSERT_EQ(expect_ship_count, res_ship_count);

}

TEST_F(PlayerFixture, testGetMapMeth) {
	size_t size_pol_expect = 100;
	std::vector<char> map;

	map = obj->getMap();

	std::cout << "Checking the size of map" << std::endl;
	ASSERT_EQ(size_pol_expect, map.size());
	std::cout << "Checking map filling" << std::endl;
	for (const auto& it : map) {
		ASSERT_EQ(it, static_cast <char>(149));
	}

}

TEST_F(PlayerFixture, testIsMoveMeth) {
	std::cout << "Checking the player's progress" << std::endl;
	bool res_flag = obj->isMove();
	ASSERT_FALSE(res_flag);
}


TEST_F(PlayerFixture, testGetNavyMeth) {
	std::vector<Ship> res_navy, expect_navy;
	std::pair<int, int> test_cord = { 10,10 };
	int dec_test = 4;
	bool is_eq;

	expect_navy.emplace_back(Ship(cords, dir_up, dec));
	std::cout << "Checking the ship count" << std::endl;
	res_navy = obj->getNavy();
	ASSERT_EQ(expect_navy.size(), res_navy.size());

	expect_navy.emplace_back(Ship(test_cord, dir_up, dec_test));
	obj->setShip(test_cord, dir_up, dec_test);
	res_navy = obj->getNavy();
	ASSERT_EQ(expect_navy.size(), res_navy.size());

	std::cout << "Checking the equality of ship coordinates" << std::endl;
	is_eq = std::equal(expect_navy.cbegin(), expect_navy.cend(), res_navy.cbegin(), res_navy.cend(), [](Ship it_exp, Ship it_res)mutable {
		std::vector <std::pair<int, int>> expect_cords_ship = it_exp.getCord();
		std::vector <std::pair<int, int>> res_cords_ship = it_res.getCord();
		for (auto i = 0, j = 0; i != expect_cords_ship.size(), j != res_cords_ship.size(); i++, j++) {
			if (expect_cords_ship[i].first!= res_cords_ship[j].first && expect_cords_ship[i].second != res_cords_ship[j].second)
				return false;
		};
		return true;
		});
	
	ASSERT_TRUE(is_eq);

}

TEST_F(PlayerFixture, testMoveStatMeth) {
	std::cout << "Checking the change of the player's turn status" << std::endl;
	bool flag_stat = true;
	bool res_flag;

	res_flag = obj->isMove();
	ASSERT_FALSE(res_flag);

	obj->moveStat(flag_stat);
	res_flag = obj->isMove();
	ASSERT_TRUE(res_flag);
}