#ifndef PASSENGER_H
#define PASSENGER_H
#include <fstream>
#include "plane.h"

using namespace std;

class Passenger
{ 
  static const int NAME_SIZE = 30;
  static const int FIRST_ROW = 1;
  static const char FIRST_SEAT = 'A';
  static const int ROW_SPACE = 2;
  short flightNum;
  short row;
  char seat;
  char name[NAME_SIZE];

public:
  Passenger();
  Passenger(short flightNum, short row, char seat, char name[NAME_SIZE]);
  static void copyPassengers();

  friend class Plane;
}; // class Passenger

#endif  // PASSENGER_H