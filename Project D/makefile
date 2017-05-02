projectD: main.o Simulator.o EA.o Weights.o LY_NN.o
	g++ -o projectD main.o Simulator.o EA.o Weights.o LY_NN.o
main.o: main.cpp
	g++ -c main.cpp
Simulator.o: Simulator.cpp
	g++ -c Simulator.cpp
EA.o: EA.cpp
	g++ -c EA.cpp
Weights.o: Weights.cpp
	g++ -c Weights.cpp
LY_NN.o: LY_NN.h
	g++ -c LY_NN.h
clean:
	rm *.o projectD
