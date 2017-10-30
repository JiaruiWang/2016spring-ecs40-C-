// Author: Sean Davis

#include <fstream>
#include <iostream>
#include <iomanip>

#include <string.h>
#include <ctype.h>
#include "plane.h"
#include "utilities.h"

#define TRUE 1

using namespace std;

int Plane::addPassenger()
{
  int row, seatNum;
  char name[MAX_NAME_SIZE];
  
  if(reserved == rows * width)
    return 0;  // false
  
  // printf("Please enter the name of the passenger: ");
  cout << "Please enter the name of the passenger: ";
  // fgets(name, MAX_NAME_SIZE, stdin);
  // strtok(name, "\r\n");
  cin.getline(name, MAX_NAME_SIZE);
  showGrid();
  
  while(TRUE)
  {
    row = getRow();
    // printf("Please enter the seat letter you wish to reserve: ");
    cout << "Please enter the seat letter you wish to reserve: ";
    seatNum = cin.get() - FIRST_SEAT;

    while(cin.get() != '\n');

    if(passengers[row - FIRST_ROW][seatNum] == NULL)
      break;

    // printf("That seat is already occupied.\nPlease try again.\n");
    cout << "That seat is already occupied.\nPlease try again.\n";
  } // while occupied seat
  
  passengers[row - FIRST_ROW][seatNum] 
    = new char[strlen(name) + 1];
  strcpy( passengers[row - FIRST_ROW][seatNum], name);
  reserved++;
  return 1;
}  // addPassenger()

Plane::~Plane()
{
  int row, seatNum;
  
  for(row = 0; row < rows; row++)
  {
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != NULL)
        delete[] passengers[row][seatNum];
    
    delete[] passengers[row];
  }  // for row
  
  delete[] passengers;
}  // freePlane


int Plane::getRow() const
{
  int row;
  
  do
  {
    // printf("\nPlease enter the row of the seat you wish to reserve: ");
    cout << "\nPlease enter the row of the seat you wish to reserve: ";
    row = getNumber();

    if(row == ERROR)
      // printf("That is an invalid row number.\nPlease try again.\n");
      cout << "That is an invalid row number.\nPlease try again.\n";
    else  // valid row number
      if(row < 1 || row > rows)
        // printf("There is no row #%d on this flight.\nPlease try again.\n", 
        //   row);
        cout << "There is no row #"<< row 
             << " on this flight.\nPlease try again.\n";
  }  while(row < 1 || row > rows);
  
  return row;
} // getRow()

  
Plane::Plane(ifstream& inf)
{
  int row, numPassenger, seatNum;
  char seat, name[MAX_NAME_SIZE];
  // fscanf(fp, "%d %d %d", &rows, &width, &reserved);
  inf >> rows >> width >> reserved;
  inf.ignore();
  // cout<<rows<<" "<<width<<" "<<reserved<<endl;
  passengers = new char** [rows];
  
  for(row = 0; row < rows; row++)
  {
    passengers[row] = new char* [width];
    
    for(seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = NULL;
  } // for each row
  
  for(numPassenger = 0; numPassenger < reserved; numPassenger++)
  {
    // fscanf(fp, "%d%c ", &row, &seat);
    row = inf.get() - ZERO;
    seat = inf.get();
    inf.ignore();
    // cout<<"row="<<row<<" seat="<<seat<<endl;
    // fgets(name, MAX_NAME_SIZE, fp);
    // strtok(name, "\r\n");
    inf.getline(name, MAX_NAME_SIZE);
    // cout<<name<<endl;
    // inf.ignore();
    seatNum = seat;
    // cout<< FIRST_ROW<<endl;
    passengers[row - FIRST_ROW][seatNum - FIRST_SEAT] = new char [strlen(name) + 1];
    strcpy(passengers[row - FIRST_ROW][seatNum - FIRST_SEAT], name);
  }  // for each passenger
}  // readPlane()


void Plane::showGrid() const
{
  int row, seatNum = 0;
  
  // printf("ROW# ");
  cout << "ROW# ";
  
  for(seatNum = 0; seatNum < width; seatNum++)
    // putchar(seatNum + FIRST_SEAT);
    cout << static_cast<char>(seatNum + FIRST_SEAT);
  
  // putchar('\n');
  cout << endl;
  
  for(row = 0; row < rows; row++)
  {
    // printf("%2d   ", row + 1);
    cout << right << setw(2) << row + 1 << "   ";
    
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum])
        // putchar('X');
        cout << 'X';
      else  // empty seat
        // putchar('-');
        cout << '-';
    // putchar('\n');
    cout << endl;
  }  // for each row
  
  // printf("\nX = reserved.\n");
  cout << "\nX = reserved.\n";
}  // showGrid()


void Plane::writePlane(ofstream &outf) const
{
  int row, seatNum;
  // fprintf(fp, "%d %d %d\n", rows, width, reserved);
  outf << rows << " " << width << " "
       << reserved << endl;

  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != NULL)
        // fprintf(fp, "%d%c %s\n", row + FIRST_ROW, seatNum + FIRST_SEAT,
        //   passengers[row][seatNum]);
        outf << row + FIRST_ROW << static_cast<char>(seatNum + FIRST_SEAT) << " "
             << passengers[row][seatNum] << endl;
}  // readPlane()
