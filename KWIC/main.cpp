//
//  main.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<string> myvector);
void testMultipleParamGetLine();
string testJoinVector(vector<string> myVector);
vector<string> testMakeCircularShifts(vector<string> data);

int main(int argc, const char * argv[]) {
    
//    testMultipleParamGetLine();
    vector<string> testVector {}, shiftsVector {};
    testVector.push_back("Oi,");
    testVector.push_back("meu");
    testVector.push_back("nome");
    testVector.push_back("é");
    testVector.push_back("Ricardo.");
        
    shiftsVector = testMakeCircularShifts(testVector);
    printVector(shiftsVector);
    
    return 0;
}


//Testing functions

void printVector(vector<string> myvector){
    for (auto mystr : myvector) {
        cout << mystr << endl;
    }
}

//MARK: getline with multiple param
void testMultipleParamGetLine(){
    string str {};
    cout << "Type something:" << endl;
    getline(cin, str);
    
    std::cout << str <<endl;
    
    cout << "Type another thing:" << endl;
    getline(cin, str, '.');
    std::cout << str <<endl;
}

//MARK: Vector -> String
string testJoinVector(vector<string> myVector){
    string line {};
    
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        if(std::next(it) == myVector.end()) // last element
        {
            line.append(*it);
        }
        else {
            line.append(*it);
            line.append(" ");
        }
    }
    
    return line;
}

//MARK: All circular shifts
vector<string> testMakeCircularShifts( vector<string> data){
    string tempShift {}, tempWord {};
    vector<string> allShifts {};
    int expectedShifts = static_cast<int>(data.size());
    
    
    for (int i = 0; i < expectedShifts; i++) {
        tempWord = data.front(); //Returns first element from vector
        data.erase(data.begin());
        data.push_back(tempWord);
        tempShift = testJoinVector(data);
        allShifts.push_back(tempShift);
    }
    
    
    return allShifts;
}
