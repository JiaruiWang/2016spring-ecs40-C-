#ifndef FLIGHT_H
#define FLIGHT_H

#define CITYLEN 20
#define BUFFERSIZE 80
#define FAULT -1
#include <stdio.h>
#include "plane.h"
#include "utilities.h"

typedef struct
{
  int flightNum;
  char origin[CITYLEN];
  char destination[CITYLEN];
  Plane *plane;
} Flight;

Flight* read_firstline(int &numFlights, FILE* pfile);
void read_Flights(int numFlights, Flight* flights, FILE* pfile);
void read_flight(Flight* flight, FILE* pfile);
void add_passenger(int numFlights, Flight* flights);
int menu(int numFlights, Flight* flights);
void to_file(int numFlights, Flight* flights);
void print_flight(FILE* pfile, Flight* flight);
void free_memory(int numFlights, Flight* flights);
#endif
