// Author: Sean Davis 

#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"
#include "flights.h"
#include "utilities.h"
#include "passenger.h"

using namespace std;

static const int MAX_CHOICE = 4; 
enum {DONE, ADD_PASSENGER, REMOVE_PASSENGER, ADD_FLIGHT, REMOVE_FLIGHT};

int getChoice()
{ 
  int choice;
  cout << "\nECS Flight Reservation Menu\n";
  cout << "0. Exit.\n";
  cout << "1. Add Passenger.\n";
  cout << "2. Remove Passenger.\n";
  cout << "3. Add Flight.\n";
  cout << "4. Remove Flight.\n";
  
  do
  {
    cout << "\nPlease enter your choice: ";
    choice = getNumber();
    
    if(choice == ERROR)
    {
      cout << "Your choice is invalid.\n";
      cout << "Please try again.\n";
    }  // if invalid format
    else // choice is a valid number
      if(choice < DONE || choice > MAX_CHOICE)
      {
        cout << choice << " is not an available choice.\n";
        cout << "Please try again.\n";
      }  // if choice out of range.
  } while(choice < DONE || choice > MAX_CHOICE  || choice == ERROR);
  
  if(choice == DONE)
    cout << "Goodbye.\n";
  
  return choice;
} // getChoice()





int main(int argc, char** argv)
{   
  int choice;
  Flights flights;
  Passenger::copyPassengers();
  flights.readFlights();

  while((choice = getChoice()) != DONE)
  {
    switch(choice)
    {
      case ADD_PASSENGER: flights.addPassenger(); break;
      case REMOVE_PASSENGER: flights.removePassenger(); break;
      case ADD_FLIGHT: flights.addFlight(); break;
      case REMOVE_FLIGHT: flights.removeFlight(); break;
    } // //  
  } //
  
  return 0;
} // main())

