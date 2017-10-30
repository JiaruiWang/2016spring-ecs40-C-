#ifndef PLANE_H
#define	PLANE_H

#include <fstream>

using namespace std;

#define MAX_NAME_SIZE 80
#define FIRST_ROW 1
#define FIRST_SEAT 'A'
#define ZERO '0'

class Plane
{
public:
  Plane(ifstream &inf);
  ~Plane();

  void writePlane(ofstream &outf) const;
  int addPassenger();

private:
  int rows;
  int width;
  int reserved;
  char ***passengers;

  int getRow() const;
  void showGrid() const;
};

#endif	// PLANE_H







