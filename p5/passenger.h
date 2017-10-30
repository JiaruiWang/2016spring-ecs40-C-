#ifndef PASSENGER_H
#define	PASSENGER_H

#include <iostream>
#include "plane.h"

class Passenger 
{
public:
  static const int NAME_LENGTH = 30;
  static const int CANCELLED = -1;
private:
  short flightNum;
  short row; 
  char seat;
  char name[NAME_LENGTH];
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  static void copyPassengers(); 
  bool operator==(const int flightNumber);
  bool operator==(const char* nam);
  Passenger& operator!();
  friend ostream& operator<<(ostream& ostrea, const Passenger& passenger);
  friend ifstream& operator>>(ifstream& inf, Plane& plane);
}; // class passengers 

#endif	// PASSENGERS_H

