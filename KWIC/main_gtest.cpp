#include <iostream>
#include "LineStorage.hpp"

#include <gtest/gtest.h>

class EmptyLineStorageTest : public testing::Test{
protected:
    LineStorage data;
};

TEST_F(EmptyLineStorageTest, empty_original_line_string){
    ASSERT_TRUE(data.originalLine_String.empty());
}

TEST_F(EmptyLineStorageTest, empty_original_line_vector){
    ASSERT_TRUE(data.originalLine_Vector.empty());
}

TEST_F(EmptyLineStorageTest, empty_shifted_variations){
    ASSERT_TRUE(data.shiftedVariations.empty());
}

TEST_F(EmptyLineStorageTest, empty_stop_words){
    ASSERT_TRUE(data.stopWords.empty());
}

TEST_F(EmptyLineStorageTest, methodCall_charsInWord_EQ_0){
    ASSERT_EQ(data.wordsInLine(), 0);
}

int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}