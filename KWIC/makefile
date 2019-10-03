KWIC : main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o
	g++ -std=c++14 -o KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o -g

main.o : main.cpp CircularShifter.hpp Alphabetizer.hpp Text_Input.hpp Output.hpp
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


clean :
#windows
#del KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o
#linux
	rm KWIC main.o LineStorage.o CircularShifter.o Alphabetizer.o I_Input.o Input.o Text_Input.o Output.o Text_Output.o