//
//  Text_Output.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 02/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Text_Output_hpp
#define Text_Output_hpp

#include "Output.hpp"

using namespace std;

class Text_Output: Output {
    
    ofstream out_file {};
    
public:
    
    void createFile();
    void printOutput();
    
    void closeFile();
    
    //MARK: Constructor
    Text_Output(string filename, vector<string> & data);
    
};

#endif /* Text_Output_hpp */