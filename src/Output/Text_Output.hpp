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

class Text_Output: public Output {
    
protected:
    std::ofstream out_file {};
    
private:
    void setup() override;
    void print() override;
    void close() override;
    
public:
    
    //MARK: Constructors
    Text_Output(std::string name, std::vector<std::string> &data); //2 Args Constructor
    Text_Output(std::vector<std::string> & data); //1 Arg Constructor
    
};

#endif /* Text_Output_hpp */
