#include <iostream>

#include "linkedlist.h"

using namespace std;

ListNode::ListNode(int data, ListNode* previous, ListNode* next) : 
  data_(data), previous_(previous), next_(next)
{} //

LinkedList::LinkedList() :Container( 0 ), head_(NULL), tail_(NULL), curr_(NULL)
{} //

LinkedList::~LinkedList()
{
  for (curr_ = head_; curr_; curr_ = head_)
  {
    head_ = curr_->next_;
    delete curr_;
  }//
}//

int* LinkedList::insert(int num)
{
  if (tail_)
    tail_ = tail_->next_ = curr_ = new ListNode(num, tail_, NULL);
  else //
    head_ = tail_ = curr_ = new ListNode(num, NULL, NULL);

  size_++;
  return &(curr_->data_);
}//

int* LinkedList::erase(int num)
{
  int* ptr = NULL;
  
  for (curr_ = head_; curr_ && ((curr_->data_ < num) || (num < curr_->data_)); 
    curr_ = curr_->next_);
  
  if (!curr_) //
    return NULL;

  size_--;

  if (curr_->previous_)
    curr_->previous_->next_ = curr_->next_;
  else // curr_ is head
    head_ = curr_->next_;

  if (curr_->next_)
  {
    curr_->next_->previous_ = curr_->previous_;
    ptr = &(curr_->next_->data_);
  }//
  else //curr_ is tail
    tail_ = curr_->previous_;

  delete curr_;
  return ptr;
}//

int* LinkedList::find(int num)
{
  for (curr_ = head_; curr_ && ((curr_->data_ < num) || (num < curr_->data_));
    curr_ = curr_->next_)
    cout << curr_->data_ << " ";

  if (curr_)
    return &curr_->data_;
  else //
    return NULL;
}//

int* LinkedList::operator++()
{
  if (!curr_)
    return NULL;

  curr_ = curr_->next_;
  
  if (!curr_)
    return NULL;
    
  return &curr_->data_;
} //

int* LinkedList::operator--()
{
  if (!curr_)
    return NULL;

  curr_ = curr_->previous_;
  
  if (!curr_)
    return NULL;
    
  return &curr_->data_;
} //