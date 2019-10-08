#include <iostream>
#include "LineStorage.hpp"

#include <gtest/gtest.h>

class LineStorageTest : public testing::Test{
protected:
    LineStorage *data;
    
    void SetUp() override{
        data = new LineStorage;
    }
    void TearDown() override{
        delete data;
    }
};

TEST_F(_LineStorage, emptyCreation){
    ///Testing empty generation for empty LineStorage
    ASSERT_EQ(data->originalLine_String, "");
    ASSERT_EQ(data->originalLine_Vector, "");
    ASSERT_EQ(data->shiftedVariations, "");
    ASSERT_EQ(data->stopWords, "");

    ///Testing functions on empty LineStorage
    ASSERT_EQ(data.charsInWord, 0);
}


int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}