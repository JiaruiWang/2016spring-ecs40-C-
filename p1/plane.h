#ifndef PLANE_H
#define PLANE_H

#include <stdio.h>
#define BUFFERSIZE 80
#define cA 'A'
#define cB 'B'
#define NOTRESERVED "-"
#define BERESERVED "X"

typedef struct
{
  int rows;
  int width;
  int reserved;
  char ***passengers;
} Plane;

void read_plane(Plane* plane, FILE* pfile);
void read_passengers(Plane* plane, FILE* pfile);
void select_seat(int &loop, int fltnum, int row, char* name, Plane* plane);
void select_row(char* name, int fltnum, Plane* plane);
void show_seat(int fltnum, Plane* plane);
void print_plane(FILE* pfile, Plane* plane);
void free_plane(Plane* plane);
#endif
