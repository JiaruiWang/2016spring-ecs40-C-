// Author: Sean Davis
#include <iostream>

#include <ctype.h>
#include <limits.h>
#include "utilities.h"

using namespace std;

#define TEN 10
#define ASCII_ZERO '0'

int getNumber()
{
  long long number = 0, OK = 1;
  char c;

  for(cin.get(c); isspace(c) && c != '\n'; cin.get(c));

  if(isdigit(c))
  {
    do
    {
      number = number * TEN + c - ASCII_ZERO;
      cin.get(c);
    }  while(isdigit(c) && number <= INT_MAX);

    while(c != '\n' && isspace(c))
      cin.get(c);

    if(c != '\n' || number > INT_MAX)
      OK = 0;
  }  // if first non-space is a digit
  else // first non-space is not a digit
    OK = 0;  // false

  while(c != '\n')
    cin.get(c);
    
  if(OK)
    return number;
  else  // invalid number
    return ERROR;
  
} // getNumber()

