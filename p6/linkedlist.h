#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "container.h"

class ListNode
{
  int data_;
  ListNode* previous_;
  ListNode* next_;
  ListNode(int data, ListNode* previous, ListNode* next);

  friend class LinkedList;
  friend class SortedLinkedList;
}; //

class LinkedList : public Container
{
protected:
  ListNode* head_;
  ListNode* tail_;
  ListNode* curr_;
public:
  LinkedList();
  ~LinkedList();
  virtual int* insert(int num);
  virtual int* erase(int num);
  virtual int* find(int num);  
  int* operator++();
  int* operator--();
}; //


#endif