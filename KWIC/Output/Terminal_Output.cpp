//
//  Terminal_Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Terminal_Output.hpp"

template<typename T>
Terminal_Output<T>::Terminal_Output(T &data)
:simpleOutput::data(data){
    
}

template<typename T>
void Terminal_Output<T>::print(){
    for (auto line : data) {
        std::cout << line << std::endl;;
    }
}
