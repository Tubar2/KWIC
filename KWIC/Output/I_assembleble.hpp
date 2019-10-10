#ifndef I_assembleble_hpp
#define I_assembleble_hpp

class I_assembleble
{
public:

    //Must be overriden functions
    virtual void assemble() = 0;
    virtual void terminate() = 0;

    virtual ~I_assembleble() = default;
};


#endif