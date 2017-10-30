#include "container.h"

Container::Container(int size) : size_(size)
{} //constructor

Container::~Container()
{} // destructor

int Container::getSize() const
{
  return size_;
} //getSize()
