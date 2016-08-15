#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "plane.h"
#include "flight.h"
#include "utilities.h"

void read_plane(Plane* plane, FILE* pfile)
{

  fscanf(pfile, "%d %d %d\n", &(plane->rows),
         &(plane->width), &(plane->reserved));
  plane->passengers = (char***)malloc(sizeof(char**)*(plane->rows));
  
  for (int i = 0; i < plane->rows; i++)
  {
    plane->passengers[i] = (char**)malloc(sizeof(char*)*(plane->width));
    
    for (int j = 0; j < plane->width; j++)
    {
      plane->passengers[i][j] = NULL;
    }// set NULL to all passenger pointer in one plane
  }// give mem to each row of plane
  
  read_passengers(plane, pfile);
}// give mem to line of rows, then each row, then call func to read passenger

void read_passengers(Plane* plane, FILE* pfile)
{
  int row;
  char wid;
  char buffer[BUFFERSIZE];
  
  for(int i = 0; i < plane->reserved; i++)
  {
    memset(buffer, cend, BUFFERSIZE);
    fscanf(pfile, "%d%c ", &row, &wid);
    get_line(buffer, pfile);
    plane->passengers[row - 1][wid - cA] =
    (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
    strcpy(plane->passengers[row - 1][wid-cA], buffer);
  }// give mem to each name, link it ot passenger pointer
}// read row# width# and name

void select_seat(int &loop, int fltnum, int row, char* name, Plane* plane)
{
  printf("Please enter the seat letter you wish to reserve: ");
  char seat = get_seat();
  
  if (isupper(seat) && seat - cA < plane->width)
  {
    if (plane->passengers[row - 1 ][seat-cA]!=NULL)
    {
      printf("That seat is already occupied.\nPlease try again.\n\n");
    }// not NULL, seat is taken
    else// NULL, seat is empty
    {
      plane->passengers[row - 1][seat - cA] =
      (char*)malloc(sizeof(char)*(strlen(name) + 1));
      strcpy(plane->passengers[row - 1][seat - cA], name);
//      printf("We have reserved seat %d%c on flight %d for %s.\n\n",
//      row,seat,fltnum, plane->passengers[row - 1][seat- cA]);
      (plane->reserved)++;
      loop = 1;
    }// if seat is empty, give mem to pointer to store name
  }// get_seat() return is upper letter within width
  else// not upper letter and within width
  {
    printf("Your seat letter is invalid.\nPlease try again.\n\n");
  }// invalid seat letter
}// call get_seat() to return seat#, if empty, reserve

void select_row(char* name, int fltnum, Plane* plane)
{
  int loop = 0;
  int row;
  
  while (loop == 0)
  {
    printf("Please enter the row of the seat you wish to reserve: ");
    row = getNumber();
    
    if (row > 0 && row <= plane->rows)
    {
      select_seat(loop, fltnum , row, name, plane);
    }// row# is number within rows, call select_seat() to read seat#
    else// row# invalid or number but out of rows
      if (row == FAULT)
      {
        printf("That is an invalid row number.\nPlease try again.\n\n");
      }// getNumber return invalid
      else// number is wrong
      {
        printf("There is no row %d on this flight.\nPlease try again.\n\n",
               row);
        continue;
      }// getNumber return number outside of rows
  }// loop to read row# using getNumber
}// getNumber to read row#, then call select_seat to read seat#

char* widletter(int width, char* letter)
{
  int i = 0;
  
  for (; i < width; i++)
  {
    letter[i] = 'A' + i;
  }// generate ABCD...
  
  letter[i] = cend;
  return letter;
}// generate seat# ABCD... within width

void print_reserved(Plane* plane)
{
  char* letter = (char*)malloc(sizeof(char)*(plane->width + 1));
  printf("ROW# %s\n", widletter(plane->width, letter));
  free(letter);
  
  for (int i = 0; i < plane->rows; i++)
  {
    printf("%2d   ", i + 1);
    
    for (int j = 0; j < plane->width; j++)
    {
      if (plane->passengers[i][j] == NULL)
      {
        printf(NOTRESERVED);
      }// print - for not reserved seat
      else// reserved
      {
        printf(BERESERVED);
      }// print X for reserved seat
    }// print -X reservation info for all seats
    
    printf("\n");
  }// print seat reservation info
  
  printf("\nX = reserved.\n\n");
}// print char of reservation

void show_seat(int fltnum, Plane* plane)
{
  if (plane->rows * plane->width == plane->reserved)
  {
    printf("We are sorry but Flight #%d is full.\n", fltnum);
    return;
  }// this flt is full

  printf("Please enter the name of the passenger: ");
  char name[BUFFERSIZE];
  memset(name, cend, BUFFERSIZE);
  int i = 0;
  char t = getchar();
  
  while(t != '\n')
  {
    name[i++] = t;
    t = getchar();
  }// read passenger's name

  print_reserved(plane);
  select_row(name, fltnum, plane);
}// show plane seat reserved info, then call select_row to input

void print_plane(FILE* pfile, Plane* plane)
{
  fprintf( pfile, "%d %d %d\n", plane->rows, plane->width, plane->reserved);
  
  for (int i = 0; i < plane->rows; i++)
  {
    for (int j = 0; j < plane->width; j++)
    {
      if (plane->passengers[i][j] != NULL)
      {
        fprintf(pfile, "%d%c %s\n", i + 1, j + 'A', plane->passengers[i][j]);
      }// print row# seat# and passenger name
    }// loop for width
  }// loop for rows
}// print plane and passenger info to file

void free_plane(Plane* plane)
{
  for (int i = 0; i < plane->rows; i++)
  {
    for (int j = 0; j < plane->width; j++)
    {
      if (plane->passengers[i][j] != NULL)
      {
        free(plane->passengers[i][j]);
      }// free nonNULL passenger name mem
    }// loop for width
    
    free(plane->passengers[i]);
  }// free name mem, then width mem of each row
  
  free(plane->passengers);
}// free name mem, then width mem, then row mem
