#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vector;

template<typename T>
std::ostream& operator<<(std::ostream& os, Vector<T>& v);

template <typename T>
class VectorIterator
{
 
  Vector<T>* vectorPtr;
  int position;
public: 
  static const int ERROR = -1;
  VectorIterator(Vector<T>* vPtr = NULL, int pos = ERROR);
  VectorIterator<T>& operator++(int dummy);
  bool operator!=(const VectorIterator<T> &vi);
  T& operator*();
}; //

template <typename T>
class ReverseVectorIterator
{
 
  Vector<T>* vectorPtr;
  int position;
public: 
  static const int ERROR = -1;
  ReverseVectorIterator(Vector<T>* vPtr = NULL, int pos = ERROR);
  ReverseVectorIterator<T>& operator++(int dummy);
  bool operator!=(const ReverseVectorIterator<T> &vi);
  T& operator*();
}; //

template<typename T>
class Vector
{
  static const int RESIZE_FACTOR = 2;
  static const int NOT_FOUND = -1;
private:
  int storage;
  int count;
  T* array;
public:
  Vector();
  Vector(const T* arr);
  Vector(const Vector<T> &v);
  ~Vector();
  Vector<T>& operator=(const Vector<T> &v);
  Vector<T>& operator+=(const Vector<T> &v);
  int size();
  int capacity();
  size_t find(const Vector<T> &v);
  Vector<T> substr(int start, int length);
  Vector<T>& insert(int start, const Vector<T> &v);
  Vector<T>& replace(int start, int length, const Vector<T> &v,
                     int substart, int sublength);
  friend std::ostream& operator<< <T> (std::ostream& os, Vector<T>& v);
  friend class VectorIterator<T>;
  friend class ReverseVectorIterator<T>;
  typedef VectorIterator<T> iterator;
  typedef ReverseVectorIterator<T> reverse_iterator;
  VectorIterator<T> end();
  VectorIterator<T> begin();
  ReverseVectorIterator<T> rend();
  ReverseVectorIterator<T> rbegin();
}; //


#include "vector.cpp"

#endif