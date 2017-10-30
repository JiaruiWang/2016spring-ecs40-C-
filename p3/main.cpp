// Author: Sean Davis 

#include <fstream>
#include <iostream>
#include <iomanip>

#include "flight.h"
#include "utilities.h"

#define DONE 0
#define MAX_CHOICE 1

using namespace std;

void addPassenger(Flight* flights, int numFlights)
{
  int i, flightNumber;
  
  // printf("Flt# Origin               Destination\n");
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < numFlights; i++)
    flights[i].printFlightInfo();

  do
  {
    cout << "\nFlight number (0 = exit): ";
    flightNumber = getNumber();

    if(flightNumber > 0)
    {
      
      for(i = 0; i < numFlights; i++)
        if(flights[i].getFlightNumber() == flightNumber)
        {
          flights[i].addPassenger();
          break;
        }  // if found match of flight

      if(i == numFlights)
      {
        // printf("We do not have a flight number %d.\n", flightNumber);
        // printf("Please try again.\n");
        cout << "We do not have a flight number " << flightNumber << 
                ".\n" << "Please try again.\n";
      }  // if flightNumber not found
    }  // if flightNumber > 0
    else // if flightNumer <= 0
      if(flightNumber == ERROR)
        // printf("That is an invalid flight number.\nPlease try again.\n");
        cout << "That is an invalid flight number.\nPlease try again.\n";
  }  while((flightNumber != 0 && i == numFlights) || flightNumber == ERROR);
}  // addPassenger()


void freeFlights(Flight *flights, int numFlights)
{
  // int i;
  
  // for(i = 0; i < numFlights; i++)
  //   delete flights[i];
  
  delete[] flights;
}  // freeFlights()


int getChoice()
{ 
  int choice;

  cout << "\nECS Flight Reservation Menu\n" << "0. Exit.\n" 
       << "1. Add Passenger.\n";
  
  do
  {
    // printf("\nPlease enter your choice: ");
    cout << "\nPlease enter your choice: ";
    choice = getNumber();
    
    if(choice == ERROR)
    {
      // printf("Your choice is invalid.\n");
      // printf("Please try again.\n");
      cout << "Your choice is invalid.\n"
           << "Please try again.\n";
    }  // if invalid format
    else // choice is a valid number
      if(choice < DONE || choice > MAX_CHOICE)
      {
        // printf("%d is not an available choice.\n", choice);
        // printf("Please try again.\n");
        cout << choice << " is not an available choice.\n"
             << "Please try again.\n";
      }  // if choice out of range.
  } while(choice < DONE || choice > MAX_CHOICE  || choice == ERROR);
  
  if(choice == DONE)
    // printf("Goodbye.\n");
    cout << "Goodbye.\n";
  
  return choice;
} // getChoice()


Flight* readFlights(int *numFlights)
{
  Flight *flights;
  int i;
  ifstream inf("reservations.txt");
  inf >> *numFlights;
  // cout << *numFlights << endl;
  // fscanf(fp, "%d", numFlights);
  flights = new Flight[*numFlights];
  
  for(i = 0; i < *numFlights; i++)
    flights[i].readFlight(inf);
  
  inf.close();
  return flights;
} // readFlights()

void writeFlights(Flight *flights, int numFlights)
{
  int i;
  // FILE *fp = fopen("reservations2.txt", "w");
  ofstream outf("reservations2.txt");
  // fprintf(fp, "%d\n", numFlights);
  outf << numFlights << endl;
  
  for(i = 0; i < numFlights; i++)
    flights[i].writeFlight(outf);
  
  outf.close();
}  // freeFlights()

int main(int argc, char** argv)
{
  int numFlights;
  Flight *flights = readFlights(&numFlights);
  
  while(getChoice() != DONE)
    addPassenger(flights, numFlights);
  
  writeFlights(flights, numFlights);
  freeFlights(flights, numFlights);

  return 0;
} // main())

