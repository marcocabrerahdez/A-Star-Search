CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

main: main.o Board.o Cell.o Taxi.o Heuristic.o Colors.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: src/main.cc include/Board.h include/Cell.h include/Taxi.h include/Heuristic.h include/Colors.h
	$(CXX) -c src/main.cc

Board.o: src/Board.cc include/Board.h
	$(CXX) -c src/Board.cc

Cell.o: src/Cell.cc include/Cell.h
	$(CXX) -c src/Cell.cc

Taxi.o: src/Taxi.cc include/Taxi.h
	$(CXX) -c src/Taxi.cc

Heuristic.o: src/Heuristic.cc include/Heuristic.h
	$(CXX) -c src/Heuristic.cc

Colors.o: src/Colors.cc include/Colors.h
	$(CXX) -c src/Colors.cc

clean:
	rm *.o output.txt