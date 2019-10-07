KWIC : main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o
	g++ -std=c++17 -o KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o -g -Wall

Main_dblp : main_dblp.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o DBLP_Input.o JSONText_Input.o
	g++ -std=c++17 -o Main_dblp main_dblp.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o DBLP_Input.o JSONText_Input.o -lcurl -I single_include/ -g -Wall


main.o : main.cpp CircularShifter.hpp Alphabetizer.hpp Input/Text_Input.hpp Output/Output.hpp Output/Text_Output.hpp Factory.hpp
	g++ -std=c++17 -c main.cpp -g -Wall
LineStorage.o : LineStorage.cpp LineStorage.hpp
	g++ -std=c++17 -c LineStorage.cpp -g -Wall
CircularShifter.o : CircularShifter.cpp CircularShifter.hpp LineStorage.hpp
	g++ -std=c++17 -c CircularShifter.cpp -g -Wall
Alphabetizer.o : Alphabetizer.cpp Alphabetizer.hpp LineStorage.hpp
	g++ -std=c++17 -c Alphabetizer.cpp -g -Wall
I_Input.o : Input/I_Input.cpp Input/I_Input.hpp LineStorage.hpp
	g++ -std=c++17 -c Input/I_Input.cpp -g -Wall
Input.o : Input/Input.cpp Input/Input.hpp Input/I_Input.hpp LineStorage.hpp
	g++ -std=c++17 -c Input/Input.cpp -g -Wall
Text_Input.o : Input/Text_Input.cpp Input/Text_Input.hpp Input/Input.hpp
	g++ -std=c++17 -c Input/Text_Input.cpp -g -Wall
Output.o : Output/Output.cpp Output/Output.hpp
	g++ -std=c++17 -c Output/Output.cpp -g -Wall
Text_Output.o : Output/Text_Output.cpp Output/Text_Output.cpp Output/Output.hpp
	g++ -std=c++17 -c Output/Text_Output.cpp -g -Wall
DBLP_Input.o : Input/DBLP_Input.cpp Input/DBLP_Input.hpp Input/I_Input.hpp LineStorage.hpp Input/Input.hpp
	g++ -std=c++17 -c Input/DBLP_Input.cpp -g -Wall -lcurl -I single_include/
JSONText_Input.o : Input/JSONText_Input.cpp Input/JSONText_Input.hpp Input/I_Input.hpp LineStorage.hpp Input/Input.hpp
	g++ -std=c++17 -c Input/JSONText_Input.cpp -g -Wall -lcurl -I single_include/
main_dblp.o : main_dblp.cpp Input/DBLP_Input.hpp CircularShifter.hpp Alphabetizer.hpp Input/Text_Input.hpp Output/Output.hpp Output/Text_Output.hpp
	g++ -std=c++17 -c main_dblp.cpp -g -Wall -lcurl -I single_include/

clean :
	rm KWIC Main_dblp *.o

#del KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o
#windows
	