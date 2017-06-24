all: sApp

sApp: SimulationApp.o Queue.h PriorityQueue.h Node.h Customer.o EmptyDataCollectionException.o
	g++ -Wall -std=c++11 -o sApp SimulationApp.o Customer.o EmptyDataCollectionException.o

SimulationApp.o: SimulationApp.cpp Queue.h PriorityQueue.h Customer.o
	g++ -c SimulationApp.cpp

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f sApp *.o