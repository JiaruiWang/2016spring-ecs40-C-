#ifndef PLANE_H
#define	PLANE_H
#include <fstream>

using namespace std;

class Plane
{
  static const int TEN = 10;
  static const int MAX_NAME_SIZE = 80;
  static const int FIRST_ROW = 1;
  static const char FIRST_SEAT = 'A';
  static const int ROW_SPACE = 2;
  static const int EMPTY = -1;
  int rows;
  int width;
  int reserved;
  int **passengers;
  int getRow() const;
  void showGrid() const;
public:
  Plane(ifstream &inf, int flightNum);
  Plane();
  ~Plane();
  int addPassenger(int flightNum);
  void removePassenger();
  void addPlane();
  void removePlane();
  void writePlane(ofstream &outf, int flightNum) const;
}; // class Plane

#endif	// PLANE_H


