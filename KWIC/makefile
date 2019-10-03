KWIC : main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o
	g++ -std=c++14 -o KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o -g -Wall

Main_dblp : main_dblp.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o DBLP_Input.o
	g++ -std=c++14 -o Main_dblp main_dblp.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o DBLP_Input.o -lcurl -I single_include/ -g -Wall


main.o : main.cpp CircularShifter.hpp Alphabetizer.hpp Text_Input.hpp Output.hpp Text_Output.hpp
	g++ -std=c++14 -c main.cpp -g -Wall
LineStorage.o : LineStorage.cpp LineStorage.hpp
	g++ -std=c++14 -c LineStorage.cpp -g -Wall
CircularShifter.o : CircularShifter.cpp CircularShifter.hpp LineStorage.hpp
	g++ -std=c++14 -c CircularShifter.cpp -g -Wall
Alphabetizer.o : Alphabetizer.cpp Alphabetizer.hpp LineStorage.hpp
	g++ -std=c++14 -c Alphabetizer.cpp -g -Wall
I_Input.o : I_Input.cpp I_Input.hpp LineStorage.hpp
	g++ -std=c++14 -c I_Input.cpp -g -Wall
Input.o : Input.cpp Input.hpp I_Input.hpp LineStorage.hpp
	g++ -std=c++14 -c Input.cpp -g -Wall
Text_Input.o : Text_Input.cpp Text_Input.hpp Input.hpp
	g++ -std=c++14 -c Text_Input.cpp -g -Wall
Output.o : Output.cpp Output.hpp
	g++ -std=c++14 -c Output.cpp -g -Wall
Text_Output.o : Text_Output.cpp Text_Output.cpp Output.hpp
	g++ -std=c++14 -c Text_Output.cpp -g -Wall
DBLP_Input.o : DBLP_Input.cpp DBLP_Input.hpp I_Input.hpp LineStorage.hpp Input.hpp
	g++ -std=c++14 -c DBLP_Input.cpp -g -Wall -lcurl -I single_include/
main_dblp.o : main_dblp.cpp DBLP_Input.hpp CircularShifter.hpp Alphabetizer.hpp Text_Input.hpp Output.hpp Text_Output.hpp
	g++ -std=c++14 -c main_dblp.cpp -g -Wall -lcurl -I single_include/

clean :
	rm KWIC Main_dblp main.o main_dblp.o Alphabetizer.o CircularShifter.o DBLP_Input.o I_Input.o Input.o LineStorage.o Output.o Text_Input.o Text_Output.o

#del KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o
#windows
	