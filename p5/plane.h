#ifndef PLANE_H
#define	PLANE_H
#include <fstream>
#include "linkedlist.h"
using namespace std;


class Plane
{
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  
  int rows;
  int width;
  int reserved;
  int flightNumber;
  LinkedList* passengers;
  int getRow() const;
  void showGrid() const;
public:
  Plane(int flightNumber);
  friend ifstream& operator>>(ifstream& inf, Plane& plane);
  friend ostream& operator<<(ostream& os, Plane& plane);
  ~Plane();
  void addFlight();
  Plane& operator++();
  Plane& operator--(int dummy);
  Plane& operator!();
  void writePlane(ofstream &outf) const;
  bool findPassenger(const char* name) const;
}; // class Plane

#endif	// PLANE_H


