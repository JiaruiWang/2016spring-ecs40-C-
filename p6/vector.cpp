#include <iostream>

#include "vector.h"

using namespace std;

int* Vector::insert(int num)
{
  if (!(size_ < getCapacity()) && !(getCapacity() < size_))
    resize();

  size_++;
  array_[size_ - 1] = num;

  return &(array_[size_ - 1]);
} // insert

int* Vector::erase(int num)
{
  int i;
  int* number = NULL;

  for (i = 0; i < size_ && !(!(array_[i] < num) && !(num < array_[i])); ++i);

  if (i < size_)
  {
    number = &(array_[i]);
    
    for (int j = i; j < size_ - 1; ++j)
      array_[j] = array_[j + 1];

    if (!(i < size_ - 1))
      number = NULL;

    size_--;
  }//
  
  return number;
} // erase

int* Vector::find(int num)
{
  int i;
  int* number = NULL;
  
  // for (int i = 0; i < size_; ++i)
  // {
  //   cout << array_[i] << " ";
  // }

  // cout << "\n--------------\n";

  for (i = 0; i < size_ && !(!(array_[i] < num) && !(num < array_[i])); ++i)
    cout << array_[i] << " ";

  if (i < size_)
    number = &(array_[i]);

  return number;
} //find

int& Vector::operator [](const int index)
{
  if ((index < size_) && !(index < 0))
    return array_[index];
  else //
  {
    cout << "Virtual seg fault.\n";
    return array_[ 0 ];
  } // 
} //
