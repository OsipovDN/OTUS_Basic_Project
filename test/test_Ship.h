#pragma once
#include "Ship.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <vector>


struct ShipFixture : public testing::Test {

    std::pair <int, int> cords{ 5,4 };
    const int dir = 1;
    const int dec = 3;
    std::vector<std::pair<int, int>> res{ {5,4},{5,3},{5,2} };
    std::unique_ptr<Ship> obj;

    static void SetUpTestSuite(){}

    static void TearDownTestSuite() {}
    void SetUp() override {
        obj = std::make_unique<Ship>(cords, dir, dec);
    }
    void TearDown() override {}

};


TEST_F(ShipFixture, InitializationObject) {

    std::vector<std::pair<int, int>>expect = obj->getCord();    

	EXPECT_EQ(ShipFixture::res, expect);

}