#pragma once
#include "Player.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>


struct PlayerFixture : public testing::Test {

    std::unique_ptr<Ship> obj;

    static void SetUpTestSuite() {}

    static void TearDownTestSuite() {}
    void SetUp() override {
        obj = std::make_unique<Ship>(cords, dir, dec);
    }
    void TearDown() override {}

};