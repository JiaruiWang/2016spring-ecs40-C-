#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "plane.h"



char* deleteN(char* buffer)
{
  buffer = strtok(buffer, "\n");
  buffer = strtok(buffer, "\r");
  return buffer;
}// delete \n and \r at the end of string

int to_int(char* p)
{
  int i = 0;
  int sum = 0;
  
  while( p[i] != cend)
  {
    sum = sum*TEN + p[i] - czero;
    i++;
  }// cend is '\ 0',
  
  return sum;
}// read file string to int, may change to fscanf

void to_char(char* a, char* p)
{
  int i = 0;
  
  while(p[i] != cend)
  {
    a[i] = p[i];
    i++;
  }// cend is '\ 0'
  
  a[i] = cend;
}// read file, copy string to string, may change to strcpy

void get_line(char* buffer, FILE* pfile)
{
  fgets(buffer, BUFFERSIZE, pfile);
  deleteN(buffer);
}// use fgets to read one line in file

int overflow(int len, char* temp)
{
  for (int i = 0; i < len; i++)
  {
    if( temp[i] - czero < 0 || temp[i]- czero > NINE)
    {
      return FAULT;
    }// string has non number
  }// loop
  
  if(len > TEN)
    return FAULT;
  int base = 0;
  
  for (int i = 0; i < len; i++)
  {
    if (base > MAX / TEN || (base == MAX / TEN && temp[i] - czero > SEVEN))
      return FAULT;
    base = base*TEN + temp[i] - czero;
  }// check number if overflow
  
  return base;
}// check string is valid , number is overflow

int getNumber()
{
  int i = 0;
  char temp[BUFFERSIZE];
  memset(temp, cend, BUFFERSIZE);

  char c = getchar();
  
  while ( c != '\n')
  {
    if( c != space)
    {
      temp[i] = c;
      i++;
    }// ignore space
    
    c = getchar();
  }// loop for all input
  
  int value = overflow(i, temp);
  
  if(value == FAULT)
  {
    return FAULT;
  }// input is overflow or non number
  
  return value;
}// read valid number from stdin

char get_seat()
{
  int i = 0;
  char temp[BUFFERSIZE];
  char c = getchar();
  
  while(c!='\n')
  {
    temp[i] = c;
    c = getchar();
    i++;
  }// get input without new line
  
  if(i > 1)
    return ' ';
  else// len of seat# is one
    return *temp;
}//read seat#
