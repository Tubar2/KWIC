#include "Unit_Tests/LineStorageTest.cpp"
#include "Unit_Tests/AlphabetizerTest.cpp"
#include "Unit_Tests/CircularShifterTest.cpp"
#include "Unit_Tests/DBLP_InputTest.cpp"

#include <iostream>
#include <gtest/gtest.h>

#include "Input/DBLP_Input.hpp"
#include "LineStorage.hpp"

int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}