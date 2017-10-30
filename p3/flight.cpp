// Author: Sean Davis

#include <fstream>
#include <iostream>
#include <iomanip>

#include <string.h>
#include "flight.h"

using namespace std;

void Flight::addPassenger()
{
  if(!plane->addPassenger())
    // printf("We are sorry but Flight #%d is full.\n", flightNum);
    cout << "We are sorry but Flight #" << flightNum << " is full.\n";
  
}  // addPassenger()


Flight::~Flight()
{
  
  delete plane;
}  // freeFlight()


int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()


void Flight::printFlightInfo() const
{
  cout << left << setw(4) << flightNum << " " << 
          left << setw(20) << origin << " " <<
          destination << endl;
}  // printFlightInfo()

void Flight::readFlight(ifstream& inf)
{
  // fscanf(fp, "%d\n", &flightNum);
  inf >> flightNum;
  inf.ignore();
  // cout << flightNum << endl;
  // fgets(origin, MAX_CITY_LENGTH, fp);
  inf.getline(origin, MAX_CITY_LENGTH);
  // inf.ignore();
  // cout << origin << endl;
  // strtok(origin, "\r\n");  // get rid of '\n' and/or '\r'
  // fgets(destination, MAX_CITY_LENGTH, fp);
  // strtok(destination, "\r\n");  // get rid of '\n'
  inf.getline(destination, MAX_CITY_LENGTH);
  // inf.ignore();
  // cout << destination << endl;
  plane = new Plane(inf);
}  // readFlight()


void Flight::writeFlight(ofstream& outf) const
{
  // fprintf(fp, "%d\n%s\n%s\n", flightNum, origin,
  //   destination);
  outf << flightNum << endl << origin << endl
       << destination << endl;
  plane->writePlane(outf);
}  // readFlight()
