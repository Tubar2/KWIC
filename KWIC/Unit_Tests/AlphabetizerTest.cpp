#include <iostream>
#include <gtest/gtest.h>

#include "../Alphabetizer.hpp"
#include "../LineStorage.hpp"

class EmptyAlphabetizerTest : public testing::Test{
protected:
    LineStorage data;
    Alphabetizer *alph;

    void SetUp() override {
        alph = new Alphabetizer(data);

        //Defining default values for data
        data.originalLine_String = "This is a default string for testing.";
        data.originalLine_Vector = {"This", "is", "a", "default", "string", "for", "testing."};
        data.stopWords = {"is", "a", "for"};
        data.shiftedVariations = {"This is a default string for testing.", "is a default string for testing. This", 
        "a default string for testing. This is", "default string for testing. This is a", 
        "string for testing. This is a default", "for testing. This is a default string", "testing. This is a default string for"};

    }

    void TearDown() override {
        delete alph;
    }
};

TEST_F(EmptyAlphabetizerTest, removing_stops){
    //Create
    std::vector<std::string> solutions {"This is a default string for testing.", "default string for testing. This is a", 
        "string for testing. This is a default", "testing. This is a default string for"};

    //ACT ~> Remove Stops
    alph->removeStops();

    ASSERT_EQ(data.shiftedVariations, solutions);
}

TEST_F(EmptyAlphabetizerTest, alphabetizing){
    //Create
    std::vector<std::string> unArranged_solutions {"This is a default string for testing.", "default string for testing. This is a", 
        "string for testing. This is a default", "testing. This is a default string for"};
    std::vector<std::string> arranged_solutions {"default string for testing. This is a", "string for testing. This is a default", 
        "testing. This is a default string for", "This is a default string for testing.", };

    //Act
    alph->removeStops();
    alph->alphabetiseData();

    ASSERT_EQ(data.shiftedVariations, arranged_solutions);
    ASSERT_NE(data.shiftedVariations, unArranged_solutions);
}
