#include <string.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "plane.h"
#include "passenger.h"
#include "utilities.h"

using namespace std;

Passenger::Passenger()
{
} //

Passenger::Passenger(short flightNum, short row, 
                     char seat, char name[NAME_SIZE]):
  flightNum(flightNum), row(row), seat(seat)
{
  strcpy(this->name, name);
} //

void Passenger::copyPassengers()
{
  ifstream inf("passengers.dat", ios::in | ios::binary);
  ofstream outf("passengers2.dat", ios::out | ios::binary);
  Passenger passenger;

  while(inf.read(reinterpret_cast<char*>(&passenger), sizeof(passenger)))
    outf.write(reinterpret_cast<char*>(&passenger), sizeof(passenger));

  inf.close();
  outf.close();
  // printf("胖胖是个坏蛋！萌萌是好人！");
} //