#include <iostream>
#include <gtest/gtest.h>

#include "../src/CircularShifter.hpp"

class CircularShifterTest : public testing::Test{
protected:
    CircularShifter *cs;
    std::vector<std::string> data {};

    void SetUp() override{
        cs = new CircularShifter(data);

        data = {"This", "is", "a", "default", "string", "for", "testing."};

    }
    void TearDown() override {
        delete cs;
    }

};

TEST_F(CircularShifterTest, creating_all_shifts){
    //Creating
    std::vector<std::string> reachedSolution {};
    std::vector<std::string> solution {"is a default string for testing. This", "a default string for testing. This is", 
        "default string for testing. This is a", "string for testing. This is a default", 
        "for testing. This is a default string", "testing. This is a default string for", "This is a default string for testing."};

    //Act
    reachedSolution = cs->makeCircularShifts();

    //Assert
    ASSERT_EQ(reachedSolution, solution);
}
