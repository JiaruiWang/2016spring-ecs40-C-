// Author: Sean Davis

#include <string.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "plane.h"
#include "passenger.h"
#include "utilities.h"

using namespace std;

Plane::Plane()
{
} //

Plane::Plane(ifstream &inf, int flightNum)
{
  int row, seatNum;
  reserved = 0;
  inf >> rows;
  inf.ignore(TEN, ',');
  inf >> width;
  inf.ignore(TEN, '\n');
  passengers = new int* [rows];
  
  for(row = 0; row < rows; row++)
  {
    passengers[row] = new int [width];   
    
    for(seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = EMPTY;
  } // for each row
  
  ifstream binf("passengers2.dat", ios::in | ios::binary);
  Passenger passenger;

  while(binf.read(reinterpret_cast<char*>(&passenger), sizeof(passenger)))
  {
    if (passenger.flightNum == flightNum)
    {
      row = passenger.row - FIRST_ROW;
      seatNum = passenger.seat - FIRST_SEAT;
      passengers[row][seatNum] = binf.tellg() / sizeof(passenger) - 1;
      reserved++;
    } //
  } //
  
  binf.close();
}  // Plane()


Plane::~Plane()
{
  for (int i = 0; i < rows; ++i)
    delete passengers[i];
  delete [] passengers;
}  // ~Plane()



int Plane::addPassenger(int flightNum)
{
  int row, seatNum;
  char name[MAX_NAME_SIZE];

  if(reserved == rows * width)   
    return 0;  // false
  
  cout << "Please enter the name of the passenger: ";
  cin.getline(name, MAX_NAME_SIZE);
  showGrid();
  
  while(true)
  {
    row = getRow();
    cout << "Please enter the seat letter you wish to reserve: ";
    seatNum = cin.get() - FIRST_SEAT;

    while(cin.get() != '\n');

    if(passengers[row - FIRST_ROW][seatNum] == EMPTY)
      break;

    printf("That seat is already occupied.\nPlease try again.\n");
  } // while occupied seat
  
  Passenger passenger(flightNum, row, seatNum + FIRST_SEAT, name);
  ofstream boutf("passengers2.dat", ios::out | ios::app | ios::binary);
  boutf.write(reinterpret_cast<char*>(&passenger), sizeof(passenger));
  passengers[row - FIRST_ROW][seatNum] 
    = boutf.tellp() / sizeof(passenger) - 1;
  reserved++;
  boutf.close();
  return 1;
}  // addPassenger()

void Plane::removePassenger()
{
  int row, seatNum;
  Passenger passenger;
  fstream binoutf("passengers2.dat", ios::in | ios::binary | ios::out);
  
  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != EMPTY)
      {
        binoutf.seekg(passengers[row][seatNum] * sizeof(passenger), ios::beg);
        binoutf.read(reinterpret_cast<char*>(&passenger), sizeof(passenger));
        cout << passenger.name << endl;
      } //

  cout << "\nName of passenger to remove: ";
  char name[MAX_NAME_SIZE];
  cin.getline(name, MAX_NAME_SIZE);

  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != EMPTY)
      {
        binoutf.seekg(passengers[row][seatNum] * sizeof(passenger), ios::beg);
        binoutf.read(reinterpret_cast<char*>(&passenger), sizeof(passenger));
        
        if(strcmp(name, passenger.name) == 0)
        {
          passenger.flightNum = EMPTY;
          binoutf.seekp(passengers[row][seatNum] * sizeof(passenger), ios::beg);
          binoutf.write(reinterpret_cast<char*>(&passenger), sizeof(passenger));
          passengers[row][seatNum] = EMPTY;
        } //
      } //

  binoutf.close();
} //

void Plane::addPlane()
{
  cout << "Rows: ";
  rows = getNumber();
  cout << "Width: ";
  width = getNumber();
  reserved = 0;
  passengers = new int* [rows];
  
  for(int row = 0; row < rows; row++)
  {
    passengers[row] = new int [width]; 

    for(int seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = EMPTY;
  } //
} //

void Plane::removePlane()
{
  int row, seatNum;

  Passenger passenger;
  fstream binoutf("passengers2.dat", ios::in | ios::binary | ios::out);
  
  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != EMPTY)
      {
        binoutf.seekg(passengers[row][seatNum] * sizeof(passenger), ios::beg);
        binoutf.read(reinterpret_cast<char*>(&passenger), sizeof(passenger));
        passenger.flightNum = EMPTY;
        binoutf.seekp(passengers[row][seatNum] * sizeof(passenger), ios::beg);
        binoutf.write(reinterpret_cast<char*>(&passenger), sizeof(passenger));
      } //

  binoutf.close();
} //

int Plane::getRow() const
{
  int row;
  
  do
  {
    cout << "\nPlease enter the row of the seat you wish to reserve: ";
    row = getNumber();

    if(row == ERROR)
      cout << "That is an invalid row number.\nPlease try again.\n";
    else  // valid row number
      if(row < 1 || row > rows)
        cout << "There is no row #" << row 
          << " on this flight.\nPlease try again.\n"; 
          
  }  while(row < 1 || row > rows);
  
  return row;
} // getRow()


void Plane::showGrid() const
{
  int row, seatNum = 0; 
  cout << "ROW# ";
  
  for(seatNum = 0; seatNum < width; seatNum++)
    cout << char(seatNum + FIRST_SEAT);
  
  cout << endl;
  
  for(row = 0; row < rows; row++)
  {
    cout << right << setw(ROW_SPACE) << row + 1 << "   ";
    
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != EMPTY)
        cout << 'X';
      else  // empty seat
        cout << '-';
    
    cout << endl;
  }  // for each row
  
  cout << "\nX = reserved.\n";
}  // showGrid()


void Plane::writePlane(ofstream &outf, int flightNum) const
{
  int row, seatNum;
  outf << rows << ',' << width << endl;
  Passenger passenger;
  ofstream boutf("passengers3.dat", ios::out | ios::app | ios::binary);
  ifstream binf("passengers2.dat", ios::in | ios::binary);
  
  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != EMPTY)
      {
        binf.seekg(passengers[row][seatNum] * sizeof(passenger), ios::beg);
        binf.read(reinterpret_cast<char*>(&passenger), sizeof(passenger));
        boutf.write(reinterpret_cast<char*>(&passenger), sizeof(passenger));
      } //

  boutf.close();
  binf.close();
}  // readPlane()
