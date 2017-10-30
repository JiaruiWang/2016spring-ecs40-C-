#ifndef FLIGHT_H
#define	FLIGHT_H

#include <iostream>
#include <fstream>
#include "plane.h"

using namespace std;

class Flight
{
  static const int MAX_CITY_LENGTH = 20;
  static const int FLIGHT_NUM_SPACE = 4;
  static const int TEN = 10;
  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;
public:
  void addPassenger() const;
  void removePassenger() const;
  void addFlight();
  void removeFlight();
  ~Flight();
  int getFlightNumber() const;
  void printFlightInfo() const;
  void readFlight(ifstream &inf);
} ;

#endif	// FLIGHT_H

