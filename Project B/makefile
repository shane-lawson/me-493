projectB: main.o Position.o Grid.o Goal.o Agent.o
	g++ -o projectB main.o Position.o Grid.o Goal.o Agent.o
main.o: main.cpp
	g++ -c main.cpp
Position.o: Position.cpp
	g++ -c Position.cpp
Grid.o: Grid.cpp
	g++ -c Grid.cpp
Goal.o: Goal.cpp
	g++ -c Goal.cpp
Agent.o: Agent.cpp
	g++ -c Agent.cpp
clean:
	rm *.o projectB moves.txt
