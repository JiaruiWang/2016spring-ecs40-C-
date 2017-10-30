airline.out : flights.o flight.o main.o plane.o utilities.o  passenger.o 
	g++ -ansi -Wall -g -o airline.out flights.o flight.o main.o plane.o passenger.o utilities.o  

main.o : main.cpp flight.h utilities.h flights.h
	g++ -ansi -Wall -g -c main.cpp
	
flights.o : flights.cpp flights.h utilities.h
	g++ -ansi -Wall -g -c flights.cpp

flight.o : flight.cpp flight.h 
	g++ -ansi -Wall -g -c flight.cpp


plane.o : plane.cpp plane.h utilities.h 
	g++ -ansi -Wall -g -c plane.cpp

passenger.o: passenger.cpp passenger.h utilities.h
	g++ -ansi -Wall -g -c passenger.cpp

utilities.o : utilities.cpp utilities.h 
	g++ -ansi -Wall -g -c utilities.cpp

clean : 
	rm -f airline.out flights.o flight.o  main.o  plane.o passenger.o utilities.o   
