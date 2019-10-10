#include "../Input/JSONText_Input.hpp"
#include "../LineStorage.hpp"

#include <gtest/gtest.h>

class valid_JSONText_Input_Test : public testing::Test {
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    JSON_Input myinput{"Resources/stops.json", data, stops};

};

class invalid_JSONText_Input_Test : public testing::Test {
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    JSON_Input myinput{"", data, stops};

};

TEST_F(valid_JSONText_Input_Test, methodCall_setup_validInput){
    ASSERT_TRUE(myinput.setup());
}

TEST_F(valid_JSONText_Input_Test, methodCall_extract_validInput){
    //Act
    myinput.open();
    myinput.extract();

    ASSERT_EQ(data.stopWords.at(0), "a");
    ASSERT_EQ(data.stopWords.at(1), "about");
}

TEST_F(invalid_JSONText_Input_Test, methodCall_setup_invalidInpu){
    ASSERT_FALSE(myinput.setup());
}

TEST_F(invalid_JSONText_Input_Test, methodCall_open_invalidInput){
    ASSERT_ANY_THROW(myinput.open());
}
