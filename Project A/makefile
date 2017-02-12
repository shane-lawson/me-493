projectA: Arm.o MAB.o Agent.o main.o
	g++ -o projectA Arm.o MAB.o Agent.o main.o
Arm.o: Arm.cpp
	g++ -c Arm.cpp
MAB.o: MAB.cpp
	g++ -c MAB.cpp
Agent.o: Agent.cpp
	g++ -c Agent.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o projectA
