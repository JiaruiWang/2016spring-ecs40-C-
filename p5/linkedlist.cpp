

#include "linkedlist.h"

ListNode::ListNode(int offse, ListNode* nex): offset(offse), next(nex)
{
}//

void LinkedList::initialize(int seatscount)
{
  ListNode* tail;
  
  for (int i = 0; i < seatscount; ++i)
  {
    ListNode* temp = new ListNode(EMPTY, 0);
    
    if (i == 0)
      head = tail = temp;
    else //
    {
      tail->next = temp;
      tail = temp;
    }//
  }//
}//

LinkedList::~LinkedList()
{
  ListNode* temp = head;
  
  while(head != 0)
  {
    head = head->next; 
    delete temp;
    temp = head;
  }//
}//

int& LinkedList::operator[](const int &seatNum)
{
  ListNode* ptr = head; 
  for (int i = 0; i != seatNum; ++i)
    ptr = ptr->next;

  return ptr->offset;
}//

const int& LinkedList::operator[](const int &seatNum) const
{
  ListNode* ptr = head; 
  for (int i = 0; i != seatNum; ++i)
    ptr = ptr->next;

  return ptr->offset;
}//

ostream& operator<<(ostream& os, LinkedList& linkedlist)
{
  ListNode* ptr = linkedlist.head;
  
  for(; ptr != 0; ptr = ptr->next)
    if(ptr->offset != LinkedList::EMPTY)
      os << 'X';
    else  // empty seat
      os << '-';

  return os;
}//
