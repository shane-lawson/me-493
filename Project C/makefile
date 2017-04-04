projectC: main.o Path.o City.o World.o
	g++ -o projectC main.o Path.o City.o World.o
main.o: main.cpp
	g++ -c main.cpp
Path.o: Path.cpp
	g++ -c Path.cpp
City.o: City.cpp
	g++ -c City.cpp
World.o: World.cpp
	g++ -c World.cpp
clean:
	rm *.o projectC paths.txt

