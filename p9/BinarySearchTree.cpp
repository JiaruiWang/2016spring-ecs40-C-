#include "BinarySearchTree.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
BSTNode<T>::BSTNode(int d, BSTNode<T>* l, BSTNode<T>* r) :
                    data(d), left(l), right(r)
{}//

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(NULL)
{}//

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
  if (root)
    makeEmpty(root);
}//

template <typename T>
void BinarySearchTree<T>::makeEmpty(BSTNode<T>* t)
{
  if (t->left)
    makeEmpty(t->left);

  if (t->right)
    makeEmpty(t->right);

  BSTNode<T>* temp = t;
  t = NULL;
  delete temp;
}//

template <typename T>
void BinarySearchTree<T>::insert(const T &value)
{
  if (root)
    insert(root, value);
  else //
    root = new BSTNode<T>(value, NULL, NULL);
}//

template <typename T>
void BinarySearchTree<T>::insert(BSTNode<T> *t, const T &value)
{
  assert(value < t->data || t->data < value);

  if (value < t->data)
    if (t->left)
      insert(t->left, value);
    else//
      t->left = new BSTNode<T>(value, NULL, NULL);
  else //
    if (t->data < value)
      if (t->right)
        insert(t->right, value);
      else //
        t->right = new BSTNode<T>(value, NULL, NULL);
    else//
      cout << "Found duplicate.\n";
}//

template <typename T>
void BinarySearchTree<T>::inOrder() const
{
  inOrder(root);
  cout << endl;
}//

template <typename T>
void BinarySearchTree<T>::inOrder(const BSTNode<T>* t) const
{
  if (!t)
    return;

  if (t->left)
    inOrder(t->left);
  
  cout << t->data << ", ";

  if (t->right)
    inOrder(t->right);
}//

template <typename T>
void BinarySearchTree<T>::postOrder() const
{
  postOrder(root);
  cout << endl;
}//

template <typename T>
void BinarySearchTree<T>::postOrder(const BSTNode<T>* t) const
{
  if (!t)
    return;

  if (t->left)
    postOrder(t->left);

  if (t->right)
    postOrder(t->right);

  cout << t->data << ", ";
}//

template <typename T>
void BinarySearchTree<T>::find(const BSTNode<T>* t, const T &value) const
{
  if (value < t->data || t->data < value)
    if (value < t->data)
      if (t->left)
        find(t->left, value);
      else//
        cout << "Not found.\n";
    else //
      if (t->right)
        find(t->right, value);
      else //
        cout << "Not found.\n";
  else//
    cout << "Found.\n";
}//

template <typename T>
void BinarySearchTree<T>::find(const T &value) const
{
  assert(root != __null);

  if (root)
    find(root, value);
  else //
    cout << "Not found.\n";
}//

template <typename T>
const BSTNode <T> * BinarySearchTree<T>::findMin(const BSTNode<T> *t) const
{
  if (!t)
    return NULL;

  if (t->left)
    return findMin(t->left);
  else //
    return t;
}//

template <typename T>
void BinarySearchTree<T>::remove(BSTNode<T>* &t, const T &value)
{
  BSTNode<T>* temp = t;
  assert(t != __null);

  if (!t)
    cout << "Not found.\n";
  else //
    if (value < t->data || t->data < value)
      if (value < t->data)
        remove(t->left, value);
      else //
        remove(t->right, value);
    else//
      if (t->left && t->right)//
      {
        t->data = findMin(t->right)->data;
        remove(t->right, t->data);
      }//
      else //
      {
        if (!t->left && !t->right)
          t = NULL;
        else //
          if (t->left && !t->right)//
            t = t->left;
          else //
            t = t->right;

        delete temp;
      }//
}//

template <typename T>
void BinarySearchTree<T>::remove(const T &value)
{
  assert(root);
  remove(root, value);
}//