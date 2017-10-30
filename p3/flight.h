#ifndef FLIGHT_H
#define	FLIGHT_H

#include "plane.h"

using namespace std;

#define MAX_CITY_LENGTH 20

class Flight
{
public:
  void addPassenger();
  ~Flight();
  void readFlight(ifstream& inf);
  void writeFlight(ofstream& outf) const;
  int getFlightNumber() const;
  void printFlightInfo() const;

private:
  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;
};
 







#endif	// FLIGHT_H

