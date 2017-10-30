#include <iostream>

#include "sortedvector.h"

using namespace std;

SortedVector::SortedVector() : Container( 0 ), capacity( 0 ), array_(NULL)
{}//

SortedVector::~SortedVector()
{
  delete [] array_;
}//

int SortedVector::getCapacity()
{
  return capacity;
} // getCapacity

void SortedVector::resize()
{
  if (!(capacity < 0) && !(0 < capacity))
  {
    capacity = 1;
    array_ = new int [capacity];
  }//

  else //
  {
    capacity *= CAPACITY_MULTIPLIER;
    int* newArray = new int [capacity];
    
    for (int i = 0; i < size_; ++i)
      newArray[i] = array_[i];

    delete [] array_;
    array_ = newArray;
  }//
}//

int* SortedVector::insert(int num)
{
  if (!(size_ < capacity) && !(capacity < size_))
    resize();

  int i;
  
  for (i = 0; i < size_ && array_[i] < num; ++i);

  if (i < size_)
  {
    for (int j = size_; i < j; --j)
      array_[j] = array_[j - 1];

    array_[i] = num;
  }//
  else //
    array_[i] = num;

  size_++;

  return &(array_[i]);
} // insert

int* SortedVector::erase(int num)
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

int* SortedVector::find(int num)
{
  int i;
  int* number = NULL;
  
  // for (int i = 0; i < size_; ++i)
  // {
  //   cout << array_[i] << " ";
  // }

  // cout << "\n--------------\n";

  for (i = 0; i < size_ && !(!(array_[i] < num) && !(num < array_[i])); ++i);

  if (i < size_)
  {
    number = &(array_[i]);
    
    for (int j = 0; j < size_ && !(!(array_[j] < num) && !(num < array_[j]));
     ++j)
      cout << array_[j] << " ";
  }//

  return number;
} //find

const int& SortedVector::operator[](int index) const
{
  if ((index < size_) && !(index < 0))
    return array_[index];
  else //
  {
    cout << "Virtual seg fault.\n";
    return array_[ 0 ];
  } // 
}//
