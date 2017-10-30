templates.out : main.o  
	g++-4.4 -ansi -Wall -g -o templates.out main.o  

main.o : main.cpp vector.h vector.cpp
	g++-4.4 -ansi -Wall -g -c main.cpp

clean : 
	rm -f templates.out main.o   
