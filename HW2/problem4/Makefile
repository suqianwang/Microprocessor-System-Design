# Makefile

CXX = g++
CXXFLAGS = -Wall -g

all: main

main: main.o transport.o TCP.o UDP.o
	$(CXX) $(CXXFLAGS) -o main main.o transport.o TCP.o UDP.o

main.o: main.cpp transport.hpp TCP.hpp UDP.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

transport.o: transport.cpp transport.hpp TCP.hpp UDP.hpp
	$(CXX) $(CXXFLAGS) -c transport.cpp

TCP.o: TCP.cpp TCP.hpp
	$(CXX) $(CXXFLAGS) -c TCP.cpp

UDP.o: UDP.cpp UDP.hpp
	$(CXX) $(CXXFLAGS) -c UDP.cpp

clean:
	rm -f *.o main