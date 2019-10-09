#ifndef JSONTEXT_OUTPUT_HPP
#define JSONTEXT_OUTPUT_HPP

#include "Output.hpp"
#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class JSON_Output: public Output {
    
protected:
    json j,k;
    std::ofstream out_file {};
    
private:
    void setup() override;
    void print() override;
    void close() override;
    
public:
    
    //MARK: Constructor
    JSON_Output(std::vector<std::string> & data);
    
};

#endif /* Text_Output_hpp */
