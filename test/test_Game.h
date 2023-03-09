#pragma once
#include "Game.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>


struct PlayerFixture : public testing::Test {
	std::unique_ptr <Player> plr1;
	std::unique_ptr <Player> plr2;


	static void SetUpTestSuite() {}

	static void TearDownTestSuite() {}
	void SetUp() override {
		Game();
	}
	void TearDown() override {}

};