#include <iostream>

#include "DBLP_Input.hpp"
#include "Text_Input.hpp"
#include "Text_Output.hpp"
#include "CircularShifter.hpp"
#include "Alphabetizer.hpp"

bool clearPrevEnv2(string filepath);

int main()
{
    string filepath {"Exits/"}, line{};
    cout << "Enter output file name: (no txt needed)" << endl;
    getline(cin, line);
    //line = "saida";

    filepath += line + ".txt";
    
    //TODO: Solution for clearPrevEnv
    if (!clearPrevEnv2(filepath)){
        exit(3);
    }
    
    //Definig both types of enums
    entryType stops = typeStops;

    LineStorage data;
    DBLP_Input input{"teste", data};
    Text_Input words("Resources/nltkstops.txt", data);

    input.setup();
    words.setup();

    //Extracting stop Words
    words.extract(stops);

    //Extracting text
    do {
        data.deletePrevInfo();
        input.extract(); //One line extraction
        
        //Creating CircularShifter object pointer
        CircularShifter * cs = new CircularShifter(data.originalLine);
        
        //Creating all shifts for stored line
        data.shiftedVariations = cs->makeCircularShifts();
        cout << "Shifts made: " << data.storedLines() << endl;
        
        //Creating alphabetizer object pointer
        Alphabetizer * alph = new Alphabetizer(data);
        
        //Removing stops and alphabetizing
        alph->removeStops();
        alph->alphabetiseData();
        
        //Creating output object
        Text_Output to(filepath, data.shiftedVariations);
        
        to.createFile();
        to.printOutput();
        
        //Closing files
        to.closeFile();
        
        //Deleting pointers
        delete cs;
        delete alph;
        
    } while (!input.reachedEND());
    
    //MARK: Perguntas pro prof
        // - Objeto criado em um do while sai do escopo nas seguintes iterações quando criado com outros parâmetros?
    
    //Closing others

    words.closeFile();

    return 0;
}

bool clearPrevEnv2(string filepath){
    
    bool opened {};
    ifstream a{};
    
    a.open(filepath, std::ifstream::out | std::ifstream::trunc);
    opened = a.is_open();
    a.close();
    return opened;
}
