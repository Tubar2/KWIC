#include <iostream>
#include <gtest/gtest.h>

#include "../LineStorage.hpp"
#include "../Input/DBLP_Input.hpp"

class withQuery_DBLP_Input_Test : public testing::Test{
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    DBLP_Input myinput{"Parnas", data, inputs};
};

class noQuery_DBLP_Input_Test : public testing::Test{
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    DBLP_Input myinput{"", data, inputs};
};

TEST_F(withQuery_DBLP_Input_Test, methodCall_setup_filledQuery){
    //Assert
    ASSERT_TRUE(myinput.setup());
}

TEST_F(withQuery_DBLP_Input_Test, methodCall_extract_filledQuery){
    //Solution
    std::vector<std::string> solution {"Parnas", "on", "Parnas", "-", "a", "life", "of", "indecision."};
    
    //Act
    myinput.open();
    myinput.extract();

    //Assert
    ASSERT_EQ(data.originalLine_Vector, solution);
}

TEST_F(noQuery_DBLP_Input_Test, methodCall_setup_noQuery){
    //Assert
    ASSERT_FALSE(myinput.setup());
}

TEST_F(noQuery_DBLP_Input_Test, methodCall_throws_open_noQuery){
    //Assert
    ASSERT_ANY_THROW(myinput.open());
}

