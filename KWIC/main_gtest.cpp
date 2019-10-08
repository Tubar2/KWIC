#include "Unit_Tests/LineStorageTest.cpp"
#include "Unit_Tests/AlphabetizerTest.cpp"
#include "Unit_Tests/CircularShifterTest.cpp"

#include <iostream>
#include <gtest/gtest.h>

#include "Input/DBLP_Input.hpp"
#include "LineStorage.hpp"

class DBLP_Input_Test : public testing::Test{
protected:
    LineStorage data;
    type stops = typeStops;
    type in = typeInput;
    DBLP_Input input();

    void SetUp() override{
        
    }
};

int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}