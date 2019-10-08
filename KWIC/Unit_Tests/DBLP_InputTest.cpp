#include <iostream>
#include <gtest/gtest.h>

#include "../LineStorage.hpp"
#include "../Input/DBLP_Input.hpp"

class DBLP_Input_Test : public testing::Test{
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    DBLP_Input myinput{data, inputs};


    void SetUp() override{
        
    }
    void TearDown() override{

    }
};
