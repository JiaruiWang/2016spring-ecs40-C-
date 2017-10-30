#include <iostream>

#include "sortedlinkedlist.h"

using namespace std;

int* SortedLinkedList::insert(int num)
{
  if (head_)
  {
    for (curr_ = head_; curr_ && curr_->data_ < num; curr_ = curr_->next_);

    if (!curr_)
      tail_ = tail_->next_ = curr_ = new ListNode(num, tail_, NULL);
    else //
    {
      if (!curr_->previous_)
      {
        curr_ = new ListNode(num, NULL, head_);
        head_->previous_ = curr_;
        head_ = curr_;
      }//
      else //
      {
        ListNode* temp = new ListNode(num, curr_->previous_, curr_);
        curr_->previous_->next_ = temp;
        curr_->previous_ = temp;
        curr_ = temp;
      }//
    }//
  }//
  else //
    head_ = tail_ = curr_ = new ListNode(num, NULL, NULL);

  size_++;
  return &(curr_->data_);  
}//

int* SortedLinkedList::erase(int num)
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

int* SortedLinkedList::find(int num)
{
  for (curr_ = head_; curr_ && ((curr_->data_ < num) || (num < curr_->data_));
    curr_ = curr_->next_);
    // cout << curr_->data_ << " ";

  if (curr_)
  {
    for (curr_ = head_; curr_ && ((curr_->data_ < num) || (num < curr_->data_));
     curr_ = curr_->next_)
      cout << curr_->data_ << " "; 
    return &curr_->data_;
  } //
  else //
    return NULL;
}//