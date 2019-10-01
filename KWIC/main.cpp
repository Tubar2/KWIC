//
//  main.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string str {};
    cout << "Type something:" << endl;
    getline(cin, str);
    
    std::cout << str <<endl;
    
    cout << "Type another thing:" << endl;
    getline(cin, str, '.');
    std::cout << str <<endl;
    
    return 0;
}
