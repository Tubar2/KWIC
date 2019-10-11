#include "../src/LineStorage.hpp"
#include "../src/Input/Text_Input.hpp"

#include <gtest/gtest.h>

class withTitle_Text_Input_Test : public testing::Test{
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    Text_Input myinput{"../src/Resources/poema.txt", data, inputs};
};

class NoTitle_Text_Input_Test : public testing::Test{
protected:
    LineStorage data;

    type stops = typeStops;
    type inputs = typeInput;

    Text_Input myinput{"", data, inputs};
};

TEST_F(withTitle_Text_Input_Test, methodCall_noThrow_open_withTitle){
    //Assert
    ASSERT_NO_THROW(myinput.open());
}

TEST_F(NoTitle_Text_Input_Test, methodCall_throws_open_noTitle){
    //Assert
    ASSERT_ANY_THROW(myinput.open());
}
