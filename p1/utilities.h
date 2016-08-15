#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdio.h>
#include "flight.h"
#define BUFFERSIZE 80
#define FAULT -1
#define TEN 10
#define NINE 9
#define SEVEN 7
#define MAX 2147483647
#define czero '0'
#define cA 'A'
#define cB 'B'
#define cend '\0'
#define space ' '

char* deleteN(char* buffer);
void get_line(char* buffer, FILE* pfile);
void to_char(char* a, char* p);
int to_int(char* a);
int getNumber();
char get_seat();
#endif
