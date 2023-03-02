#pragma once
#include "Ship.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>


struct ShipFixture : public testing::Test {

    std::pair <int, int> cords{ 5,4 };
    const int dir = 1;
    const int dec = 3;
    std::vector<std::pair<int, int>> expect_cords{ {5,4},{5,3},{5,2} };
    std::unique_ptr<Ship> obj;

    static void SetUpTestSuite(){}

    static void TearDownTestSuite() {}
    void SetUp() override {
        obj = std::make_unique<Ship>(cords, dir, dec);
    }
    void TearDown() override {}

};


TEST_F(ShipFixture, InitializationShipObject) {

    std::vector<std::pair<int, int>>res = obj->getCord();    

	EXPECT_EQ(res, expect_cords);

}

TEST_F(ShipFixture, TestingHitMeth) {

    std::pair<int,int>cords_test{ 4,1 };

    EXPECT_TRUE(obj->isHit(cords));
    EXPECT_FALSE(obj->isHit(cords_test));
}

TEST_F(ShipFixture, TestingIsLifeMeth) {
    for (int i = 0; i < dec;++i) {
        obj->isHit(expect_cords[i]);
        if (i == dec - 1) {
            EXPECT_FALSE(obj->isLife());
        }
        else
            EXPECT_TRUE(obj->isLife());
    }
    
}

TEST_F(ShipFixture, TestingGetCordMeth) {

    std::vector<std::pair<int, int>>res = obj->getCord();

    EXPECT_EQ(expect_cords, res);

}