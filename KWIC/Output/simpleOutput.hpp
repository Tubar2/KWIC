#ifndef simpleOutput_hpp
#define simpleOutput_hpp

#include "I_Outputable.hpp"

template<class Storage>
class simpleOutput : public I_Outputable {
private:
    virtual void print();
protected:
    Storage &data;

public:

    //Overriden function
    void printContent();

    //Contructor and destructor
    simpleOutput(Storage_t & data); //1 Arg Constructor
    virtual ~simpleOutput() = default;
};



#endif