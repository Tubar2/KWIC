#ifndef I_Storable_hpp
#define I_Storable_hpp

template<class Storage>
class I_Storable{
private:

    Storage originalLine;      //Original_Line
    Storage shiftedVariations; //All shifted variations of line
    Storage stopWords;         //All stop words


public:
    //Must be Implemented fucntions
    virtual void deletePrevInfo() = 0;

    //Getter and Setter
    void set_originalLine(Storage data){originalLine = data}        //Sets original Line var
    void set_shiftedVariations(Storage data){shiftedVariations = data} //Sets shifted Variations var
    void set_stopWords(Storage data){stopWords = data}         //Sets stop Words var

    Storage get_originalLine(){return originalLine}        //Gets original Line var
    Storage get_shiftedVariations(){return shiftedVariations} //Gets shifted Variations var
    Storage get_stopWords(){return stopWords}         //Gets stop Words var

    virtual ~I_Storable() = default;
};

#endif /* LineStorage_hpp */
