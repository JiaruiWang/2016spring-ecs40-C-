#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

class LinkedList;

class ListNode
{
  int offset;
  ListNode* next;
  ListNode(int offse, ListNode* nex);
  friend class LinkedList;
  friend ostream& operator<<(ostream& os, LinkedList& linkedlist);
}; //

class LinkedList
{
  ListNode* head;
public:
  static const int EMPTY = -1;
  void initialize(int seatscount);
  ~LinkedList();
  int& operator[](const int &seatNum);
  const int& operator[](const int &seatNum) const;
  friend ostream& operator<<(ostream& os, LinkedList& linkedlist);
}; //





#endif