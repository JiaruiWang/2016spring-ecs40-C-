#include <iostream>
#include "vector.h"

template <typename T>
VectorIterator<T>::VectorIterator(Vector<T>* vPtr, int pos) :
  vectorPtr(vPtr), position(pos)
{}//

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator++(int dummy)
{
  ++position;
  
  if (position >= vectorPtr->count)
    position = ERROR;

  return *this;
}//

template <typename T>
bool VectorIterator<T>::operator!=(const VectorIterator<T> &vi)
{
  if (vectorPtr == vi.vectorPtr)
  {
    if (position == vi.position)
      return false;
    else //
      return true;
  } //
  else //
    return true;
}//

template <typename T>
T& VectorIterator<T>::operator*()
{
  return vectorPtr->array[position];
}//

template <typename T>
VectorIterator<T> Vector<T>::end()
{
  return VectorIterator<T>(this, VectorIterator<T>::ERROR);
}//

template <typename T>
VectorIterator<T> Vector<T>::begin()
{
  return VectorIterator<T>(this, 0);
}//

template <typename T>
ReverseVectorIterator<T>::ReverseVectorIterator(Vector<T>* vPtr, int pos) :
  vectorPtr(vPtr), position(pos)
{}//

template <typename T>
ReverseVectorIterator<T>& ReverseVectorIterator<T>::operator++(int dummy)
{
  --position;

  if (position >= vectorPtr->count || position < 0)
    position = ERROR;

  return *this;
}//

template <typename T>
bool ReverseVectorIterator<T>::operator!=(const ReverseVectorIterator<T> &vi)
{
  if (vectorPtr == vi.vectorPtr)
  {
    if (position == vi.position)
      return false;
    else //
      return true;
  } //
  else //
    return true;
}//

template <typename T>
T& ReverseVectorIterator<T>::operator*()
{
  return vectorPtr->array[position];
}//

template <typename T>
ReverseVectorIterator<T> Vector<T>::rend()
{
  return ReverseVectorIterator<T>(this, ReverseVectorIterator<T>::ERROR);
}//

template <typename T>
ReverseVectorIterator<T> Vector<T>::rbegin()
{
  return ReverseVectorIterator<T>(this, count - 1);
}//

template <typename T>
int Vector<T>::size()
{
  return count;
}//

template <typename T>
int Vector<T>::capacity()
{
  return storage;
}//

template <typename T>
Vector<T>::Vector() : storage( 0 ), count( 0 ), array(NULL)
{} //

template <typename T>
Vector<T>::Vector(const T* arr)
{
  for (count = 0; arr[count] != 0; count++);
  
  storage = count;
  array = new T [storage];

  for (int i = 0; i < count; ++i)
    array[i] = arr[i];
}//

template <typename T>
Vector<T>::Vector(const Vector<T> &v)
{
  storage = v.storage;
  count = v.count;
  array = new T [storage];

  for (int i = 0; i < count; ++i)
    array[i] = v.array[i];
}//

template <typename T>
Vector<T>::~Vector()
{
  delete [] array;
}//

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v)
{
  if (this == &v)
    return *this;

  delete [] array;
  count = storage = v.count;
  array = new T [storage];

  for (int i = 0; i < count; ++i)
    array[i] = v.array[i];

  return *this;
}//

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T> &v)
{
  if (count + v.count > storage)
  {
    if (count + v.count < storage * RESIZE_FACTOR)
      storage *= RESIZE_FACTOR;
    else //
      storage = count + v.count;

    T* temp = array;
    array = new T [storage];

    for (int i = 0; i < count; ++i)
      array[i] = temp[i];

    delete [] temp;
  }//

  for (int i = 0; i < v.count; ++i)
    array[i + count] = v.array[i];

  count += v.count;
  return *this;
}//

template <typename T>
size_t Vector<T>::find(const Vector<T> &v)
{
  for (int i = 0; i <= count - v.count; ++i)
  {
    int j;

    for (j = 0; j < v.count && v.array[j] == array[j + i]; ++j);

    if (j == v.count)
      return (size_t) i;
  }//

  return (size_t) NOT_FOUND;
}//

template <typename T>
Vector<T> Vector<T>::substr(int start, int length)
{
  Vector<T> v;
  v.count = v.storage = length;
  v.array = new T [v.storage];

  for (int i = 0; i < v.count; ++i)
    v.array[i] = array[i + start];

  return v;
}//

template <typename T>
Vector<T>& Vector<T>::insert(int start, const Vector<T> &v)
{
  if (count + v.count > storage)
    while(count + v.count > storage)
      storage *= RESIZE_FACTOR;

  T* temp = array;
  array = new T [storage];

  for (int i = 0; i < start; ++i)
    array[i] = temp[i];

  for (int i = 0; i < v.count; ++i)
    array[i + start] = v.array[i];

  for (int i = 0; i < count - start; ++i)
    array[i + start + v.count] = temp[i + start];

  count += v.count;
  delete temp;
  return *this;
}//

template <typename T>
Vector<T>& Vector<T>::replace(int start, int length, const Vector<T> &v,
                              int substart, int sublength)
{
  while(count + sublength - length > storage)
  {
    if (count + sublength - length < storage * RESIZE_FACTOR)
      storage *= RESIZE_FACTOR;
    else //
      storage = count + sublength - length;
  }//

  T* temp = array;
  array = new T [storage];

  for (int i = 0; i < start; ++i)
    array[i] = temp[i];

  for (int i = 0; i < sublength; ++i)
    array[i + start] = v.array[i + substart];

  for (int i = 0; i < count - start - length; ++i)
    array[i + start + sublength] = temp[i + start + length];

  count = count + sublength - length;
  delete temp;
  return *this;
}//

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T>& v)
{
  for (int i = 0; i < v.count; ++i)
    os << v.array[i];

  return os;
}//