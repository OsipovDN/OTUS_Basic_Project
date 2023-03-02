#pragma once
#include "Player.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>


struct PlayerFixture : public testing::Test {
    int s_count_test = 10;
    size_t size_pol=10;
    size_t size_pol_expect = 100;
    std::vector <char> map_shot;

    std::unique_ptr<Player> obj;

    static void SetUpTestSuite() {}

    static void TearDownTestSuite() {}
    void SetUp() override {
        obj = std::make_unique<Player>(size_pol);
    }
    void TearDown() override {}

};

TEST(Player, initializationPlayerObject) {
    size_t size_pol = 10;
    size_t size_pol_expect = 100;
    std::vector<char> map;

    Player obj (size_pol);
    map = obj.getMap();

    ASSERT_EQ(size_pol_expect, map.size());
    for (const auto& it : map) {
        ASSERT_EQ(it, static_cast <char>(149));
    }

}