#ifndef DBLP_INPUT_H
#define DBLP_INPUT_H

#include "I_Input.hpp"
#include "LineStorage.hpp"

#include <iostream>
#include <memory>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

class DBLP_Input : public I_Input{

    virtual void read(LineStorage & data) const override{
        
    }

    virtual ~DBLP_Input() = default;

};

#endif