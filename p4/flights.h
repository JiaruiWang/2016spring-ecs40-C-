#ifndef FLIGHTS_H
#define FLIGHTS_H

#include "flight.h"

class Flights
{
  static const int RESIZE_MUL = 2;
  static const int INIT_CAP = 2;
  static const int TEN = 10;

  int capacity;
  int size;
  Flight** flights;
public:
  Flights();
  ~Flights();
  void readFlights();
  void addFlight();
  void removeFlight();
  void addPassenger() const;
  void removePassenger() const;
  void insert(Flight* newFlight);
} ;
 



#endif  // FLIGHT_H