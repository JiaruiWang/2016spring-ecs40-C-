


all: clean flight.o utilities.o plane.o main.o airline.out


utilities.o: utilities.h
	g++ -Wall -g -c utilities.cpp

plane.o: plane.h
	g++ -Wall -g -c plane.cpp 

flight.o: flight.h
	g++ -Wall -g -c flight.cpp

main.o: flight.h utilities.h plane.h
	g++ -Wall -g -c main.cpp

airline.out: main.o utilities.o plane.o flight.o
	g++ -Wall -g utilities.o plane.o flight.o main.o -lm -o airline.out

clean:
	rm -rf *.o
	rm -rf airline.out


