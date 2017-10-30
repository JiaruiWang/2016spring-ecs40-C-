#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
protected:
  int size_;

public:
  Container(int size);
  virtual ~Container();
  int getSize() const;
  virtual int* insert(int num) = 0;
  virtual int* erase(int num) = 0;
  virtual int* find(int num) = 0;
}; //class container









#endif