#include <iostream>
#include <gtest/gtest.h>

#include "../LineStorage.hpp"

class EmptyLineStorageTest : public testing::Test{
protected:
    LineStorage data;
};

class FilledLineStorageTest : public testing::Test{
protected:
    LineStorage data;

    void SetUp() override{
        data.originalLine_String = "This is a default string for testing.";
        data.originalLine_Vector = {"This", "is", "a", "default", "string", "for", "testing."};
        data.stopWords = {"is", "a", "for"};
        data.shiftedVariations = {"This is a default string for testing.", "default string for testing. This is a", 
        "string for testing. This is a default", "testing. This is a default string for"};
    }

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

TEST_F(EmptyLineStorageTest, methodCall_wordsInLine_inEmpty){
    ASSERT_EQ(data.wordsInLine(), 0);
}

TEST_F(EmptyLineStorageTest, methodCall_charsInWord_inEmpty_handles_0){
    ASSERT_EQ(data.charsInWord(0), 0);
}

TEST_F(EmptyLineStorageTest, methodCall_charsInWord_inEmpty_handles_negative){
    ASSERT_EQ(data.charsInWord(-1), 0);
    ASSERT_EQ(data.charsInWord(-5), 0);
    ASSERT_EQ(data.charsInWord(-10), 0);
}

TEST_F(EmptyLineStorageTest, methodCall_charsInWord_inEmpty_handles_positive){
    ASSERT_EQ(data.charsInWord(1), 0);
    ASSERT_EQ(data.charsInWord(5), 0);
    ASSERT_EQ(data.charsInWord(10), 0);
}

TEST_F(EmptyLineStorageTest, methodCall_getWord_inEmpty_handles_0){
    ASSERT_EQ(data.getWord(0), "");
}

TEST_F(EmptyLineStorageTest, methodCall_getWord_inEmpty_handles_negative){
    ASSERT_EQ(data.getWord(-1), "");
    ASSERT_EQ(data.getWord(-5), "");
    ASSERT_EQ(data.getWord(-10), "");
}

TEST_F(EmptyLineStorageTest, methodCall_getWord_inEmpty_handles_positive){
    ASSERT_EQ(data.getWord(1), "");
    ASSERT_EQ(data.getWord(5), "");
    ASSERT_EQ(data.getWord(10), "");
}

TEST_F(FilledLineStorageTest, filled_original_line_string){
    ASSERT_EQ(data.originalLine_String, "This is a default string for testing.");
}

TEST_F(FilledLineStorageTest, filled_original_line_vector){
    ASSERT_EQ(data.originalLine_Vector.at(0), "This");
    ASSERT_EQ(data.originalLine_Vector.at(1), "is");
    ASSERT_EQ(data.originalLine_Vector.at(2), "a");
    ASSERT_EQ(data.originalLine_Vector.at(3), "default");
    ASSERT_EQ(data.originalLine_Vector.at(4), "string");
    ASSERT_EQ(data.originalLine_Vector.at(5), "for");
    ASSERT_EQ(data.originalLine_Vector.at(6), "testing.");
}

TEST_F(FilledLineStorageTest, methodCall_wordsInLine_inFilled){
    ASSERT_EQ(data.wordsInLine(), 7);
}

TEST_F(FilledLineStorageTest, filled_original_stops_vector){
    ASSERT_EQ(data.stopWords.at(0), "is");
    ASSERT_EQ(data.stopWords.at(1), "a");
    ASSERT_EQ(data.stopWords.at(2), "for");
}

TEST_F(FilledLineStorageTest, methodCall_storedStops_inFilled){
    ASSERT_EQ(data.storedStops(), 3);
}

TEST_F(FilledLineStorageTest, methodCall_storedLines_inFilled){
    ASSERT_EQ(data.storedLines(), 4);
}

TEST_F(FilledLineStorageTest, methodCall_charsInWord_inFilled_handles_negative){
    ASSERT_EQ(data.charsInWord(-1), 0);
    ASSERT_EQ(data.charsInWord(-5), 0);
    ASSERT_EQ(data.charsInWord(-10), 0);
}

TEST_F(FilledLineStorageTest, methodCall_charsInWord_inFilled_handles_positive){
    ASSERT_EQ(data.charsInWord(1), 2);
    ASSERT_EQ(data.charsInWord(5), 3);
}

TEST_F(FilledLineStorageTest, methodCall_charsInWord_inFileed_handles_beyond_positive){
    ASSERT_EQ(data.charsInWord(10), 0);
}

TEST_F(FilledLineStorageTest, methodCall_getWord_inFilled_handles_negative){
    ASSERT_EQ(data.getWord(-1), "");
    ASSERT_EQ(data.getWord(-5), "");
    ASSERT_EQ(data.getWord(-10), "");
}

TEST_F(FilledLineStorageTest, methodCall_getWord_inFilled_handles_positive){
    ASSERT_EQ(data.getWord(1), "is");
    ASSERT_EQ(data.getWord(5), "for");
}

TEST_F(FilledLineStorageTest, methodCall_getWord_inFilled_handles_beyond_positive){
    ASSERT_EQ(data.getWord(10), "");
}

TEST_F(FilledLineStorageTest, methodCall_getwordFromString_inFilled_handles_positive){
    std::string testString {"My new testing string"};

    ASSERT_EQ(data.getWordFromString(0, testString), "My");
    ASSERT_NE(data.getWordFromString(0, testString), "My ");
    ASSERT_EQ(data.getWordFromString(1, testString), "new");
    ASSERT_NE(data.getWordFromString(1, testString), "new ");
}

TEST_F(FilledLineStorageTest, methodCall_getwordFromString_inFilled_handles_negative){
    std::string testString {"My new testing string"};

    ASSERT_EQ(data.getWordFromString(-1, testString), "Word not found");
}

TEST_F(FilledLineStorageTest, methodCall_getwordFromString_handles_inFilled_beyond_positve){
    std::string testString {"My new testing string"};

    ASSERT_EQ(data.getWordFromString(10, testString), "Word not found");
}

TEST_F(FilledLineStorageTest, methodCall_getChar_inFilled_handles_valid_positives){
    ASSERT_EQ(data.getChar(0,0), 'T');
    ASSERT_EQ(data.getChar(0,1), 'h');
    ASSERT_EQ(data.getChar(0,2), 'i');
    ASSERT_EQ(data.getChar(0,3), 's');

    ASSERT_EQ(data.getChar(1,0), 'i');
    ASSERT_EQ(data.getChar(1,1), 's');
}

TEST_F(FilledLineStorageTest, methodCall_getChar_inFilled_handles_invalid_inputs){
    //Valid word, invallid letter
    ASSERT_EQ(data.getChar(0,4), '\0');
    ASSERT_EQ(data.getChar(1,4), '\0');
    ASSERT_EQ(data.getChar(-1,4), '\0');

    //Invalid letter, valid letter
    ASSERT_EQ(data.getChar(10,4), '\0');
    ASSERT_EQ(data.getChar(0,-1), '\0');
}

TEST_F(FilledLineStorageTest, methodCall_deletePrevInfo){
    //Act ~> Deleting previous info into empty Enviroment
    data.deletePrevInfo();

    //Assert ~> Checking if data was cleared, but stops mantained
    ASSERT_TRUE(data.originalLine_String.empty());
    ASSERT_TRUE(data.originalLine_Vector.empty());
    ASSERT_TRUE(data.shiftedVariations.empty());
    ASSERT_FALSE(data.stopWords.empty());
}