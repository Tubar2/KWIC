#include "../Output/Text_Output.hpp"

#include <gtest/gtest.h>

class withTitle_Text_Output_Test : public testing::Test{
protected:

    std::vector<std::string> data {"This is a default string for testing.", "is a default string for testing. This", 
        "a default string for testing. This is", "default string for testing. This is a", 
        "string for testing. This is a default", "for testing. This is a default string", "testing. This is a default string for"};

    Text_Output myoutput{"No-AccessFolder/cantDo.txt", data};
};

TEST_F(withTitle_Text_Output_Test, methodCall_open_noAccessToFolder){
    ASSERT_ANY_THROW(myoutput.assemble());
}
