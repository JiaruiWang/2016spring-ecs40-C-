#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilities.h"
#include "flight.h"
#include "plane.h"

int main()
{
  int numFlights;
  FILE* pfile = fopen("reservations.txt", "r");
  Flight* flights = read_firstline(numFlights, pfile);
  read_Flights(numFlights, flights, pfile);
  
  while( 1 )
  {
    if (menu(numFlights, flights) == 0)
    {
      break;
    }// input of main menu is 0 to exit
  }// loop of main menu
  
  to_file(numFlights, flights);
  return 0;
}// declaration of amount of flts, file pointer, read all info, operation menu
 // write info to file, and free mem




  


