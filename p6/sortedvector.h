#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include "container.h"

class SortedVector : public Container
{
  static const int CAPACITY_MULTIPLIER = 2;
private:
  int capacity;

protected:
  int* array_;
  void resize();
public:
  SortedVector();
  ~SortedVector();
  int getCapacity();
  virtual int* insert(int num);
  virtual int* erase(int num);
  virtual int* find(int num);
  const int& operator [](int index) const;
}; //


#endif