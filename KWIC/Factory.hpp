//
//  Factory.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Factory_hpp
#define Factory_hpp

#include <memory>
#include "CircularShifter.hpp"
#include "Alphabetizer.hpp"

template <class Reader_tMain, class Reader_tStops, class Printer_t, class Storage_t>
class Factory {
    Reader_tMain &reader_m;
    Reader_tStops &reader_s;
    Printer_t &printer;
    Storage_t &data;
    
public:
    Factory(Reader_tMain &reader1, Reader_tStops &reader2, Printer_t &printer, Storage_t &data)
    :reader_m(reader1), reader_s(reader2), printer(printer), data(data){
        
    }
    
    void run(){
        
        //Opening inputs
        try
        {
            reader_m.open();
            reader_s.open();
        }
        catch(const char* e)
        {
            std::cout << e << std::endl;
            exit(1);
        }
        
        //Extracting stop Words then closing reader
        try
        {
            reader_s.extract();
            reader_s.close();
        }
        catch(const char* e)
        {
            std::cout << e << std::endl;
            exit(2);
        }
        
        //Creating CircularShifter object pointer
        auto cs = std::make_unique<CircularShifter>(data.originalLine_Vector);
        
        //Creating alphabetizer object pointer
        auto alph = std::make_unique<Alphabetizer>(data);
        
        //Opening output file
        try
        {
            printer.assemble();
        }
        catch(const char* e)
        {
            std::cerr << e << std::endl;
            exit(3);
        }
        
        //Extracting text 1 line at a time
        do {
            data.deletePrevInfo();
            try
            {
                reader_m.extract();      //One line extraction
            }
            catch(const char* e)
            {
                std::cerr << e << std::endl;
                exit(4);
            }
            
            //Creating all shifts for stored line
            data.shiftedVariations = cs->makeCircularShifts();
            
            //Removing stops and alphabetizing
            alph->removeStops();
            alph->alphabetiseData();
            
            printer.printContent();
            
        } while (!reader_m.reachedEND());
        
        //Closing
        printer.terminate();
        reader_m.close();
    }
};

#endif /* Factory_hpp */
