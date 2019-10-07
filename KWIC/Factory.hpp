//
//  Factory.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Factory_hpp
#define Factory_hpp

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
        reader_m.open();
        reader_s.open();
        
        //Extracting stop Words then closing reader
        reader_s.extract();
        reader_s.close();
        
        //Creating CircularShifter object pointer
        CircularShifter * cs = new CircularShifter(data.originalLine_Vector);
        
        //Creating alphabetizer object pointer
        Alphabetizer * alph = new Alphabetizer(data);
        
        //Opening output file
        printer.createFile();
        
        //Extracting text 1 line at a time
        do {
            data.deletePrevInfo();
            reader_m.extract();      //One line extraction
            
            //Creating all shifts for stored line
            data.shiftedVariations = cs->makeCircularShifts();
            
            //Removing stops and alphabetizing
            alph->removeStops();
            alph->alphabetiseData();
            
            printer.printOutput();
            
        } while (!reader_m.reachedEND());
        
        //Deleting pointers
        delete cs;
        delete alph;
        
        //Closing
        printer.closeFile();
        reader_m.close();
    }
};

#endif /* Factory_hpp */
