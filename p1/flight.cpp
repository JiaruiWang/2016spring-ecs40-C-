#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "flight.h"
#include "plane.h"

void read_Flights(int numFlights, Flight* flights, FILE* pfile)
{
  int i = 0;
  
  while (numFlights > 0)
  {
    read_flight(&flights[i], pfile);
    numFlights--;
    i++;
  }// loop for each flight
  
  fclose(pfile);
}// read all flights, call func to read each flt

void read_flight(Flight* flight, FILE* pfile)
{
  char buffer[BUFFERSIZE];
  get_line(buffer, pfile);
  flight->flightNum = to_int(buffer);
  get_line(buffer, pfile);
  to_char(flight->origin, buffer);
  get_line(buffer, pfile);
  to_char(flight->destination, buffer);
  flight->plane = (Plane*)malloc(sizeof(Plane));
  read_plane(flight->plane, pfile);
}// read info of each flight, call func to read plane info of each flt

Flight* read_firstline(int &numFlights, FILE* pfile)
{
  fscanf(pfile, "%d\n", &numFlights);
  return (Flight*)malloc(sizeof(Flight)*numFlights);
}// read amount of flts

void number_isflt(int &loop, int fltnum, int numFlights, Flight* flights)
{
  int i = 0;
  
  for ( ; i < numFlights; i++)
  {
    if(fltnum == flights[i].flightNum)
    {
      show_seat(flights[i].flightNum, flights[i].plane);
      loop = 1;
      break;
    }// find out if there is a flt has # same with getNumber() got
  }// loop for all flt#
  
  if (i == numFlights)
    printf("We do not have a flight number %d.\nPlease try again.\n\n", fltnum);
}// chech number is a flt#

void add_passenger(int numFlights, Flight* flights)
{
  printf("Flt# Origin               Destination\n");
  
  for (int i = 0; i < numFlights; i++)
  {
    printf("%-5d", flights[i].flightNum);
    printf("%-21s", flights[i].origin);
    printf("%s\n", flights[i].destination);
  }// print flt info of each flt
  
  printf("\n");
  int loop = 0;
  
  while (loop == 0)
  {
    printf("Flight number (0 = exit): ");
    int fltnum = getNumber();
    
    if (fltnum == FAULT)
    {
      continue;
    }// getNumber() read illegal flt number, return fault, continue to read
    
    if (fltnum == 0)
    {
      break;
    }// getNumber() read 0 and return it, break loop to return to pre menu
    
    number_isflt(loop, fltnum, numFlights, flights);
  }// loop to get valid flt# using getNumber()
}// add passenger, call show_seat to show plane info

void number_ischoice(int &choice, int numFlights, Flight* flights)
{
  if( choice == 1)
  {
    add_passenger(numFlights, flights);
    printf("\nECS Flight Reservation Menu\n0. Exit.\n1. Add Passenger.\n\n");
    choice = FAULT;
  }// choice is 1 to add passenger
  else// choice is not 0 or 1, but is a number, reinput
  {
    printf("%d is not an available choice.\nPlease try again.\n\n", choice);
    choice = FAULT;
  }// choice is 1 or invalid
}// if choice is a flt#

int menu(int numFlights, Flight* flights)
{
  printf("\nECS Flight Reservation Menu\n0. Exit.\n1. Add Passenger.\n\n");
  int choice = FAULT;
  
  while (choice == FAULT)
  {
    printf("Please enter your choice: ");
    choice = getNumber();
    
    if (choice != FAULT)
    {
      if (choice == 0)
      {
        printf("Goodbye.\n");
        break;
      }// choice is 0, exit
      else// choice is not 0, keep running
        number_ischoice(choice, numFlights, flights);
    }// read choice input 0 or 1 or other number
    else// choice is fault, getNumber() read other than number or overflow int
    {
      printf("Your choice is invalid.\nPlease try again.\n\n");
    }// not number input or overflow
  }// read choice
  
  return 0;
}// main menu

void print_flight(FILE* pfile, Flight* flight)
{
  fprintf( pfile, "%d\n%s\n%s\n", flight->flightNum,
          flight->origin, flight->destination);
  print_plane(pfile, flight->plane);
}// print flt info of each flight, call func to print plane info of
 // each flight to file
void free_memory(int numFlights, Flight* flights)
{
  for (int i = 0; i < numFlights; i++)
  {
    free_plane(flights[i].plane);
    free(flights[i].plane);
  }// loop to call func to free each  passenger mem first, then free plane mem
  
  free(flights);
}// call func to free plane passenger memory, then free plane and flight mem

void to_file(int numFlights, Flight* flights)
{
  FILE* pfile = fopen("reservations2.txt", "w");
  fprintf(pfile, "%d\n", numFlights);
  int i = 0;
  int count = numFlights;
  
  while (count > 0)
  {
    print_flight(pfile, &flights[i]);
    count--;
    i++;
  }// loop to call func to print each flt info
  
  free_memory(numFlights, flights);
}// write all info to file, then free mem
