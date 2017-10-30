#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree;

template <typename T>
class BSTNode
{
  T data;
  BSTNode<T>* left;
  BSTNode<T>* right;
public:
  BSTNode<T>(int d, BSTNode<T>* l, BSTNode<T>* r);
  friend class BinarySearchTree<T>;
}; //

template <typename T>
class BinarySearchTree
{
  BSTNode<T>* root;
  void insert(BSTNode<T>* t, const T &value);
  void inOrder(const BSTNode<T>* t) const;
  void postOrder(const BSTNode<T>* t) const;
  void find(const BSTNode<T>* t, const T &value) const;
  void remove(BSTNode<T>* &t, const T &value);
  const BSTNode <T> * findMin(const BSTNode<T> *t) const;
  void makeEmpty(BSTNode<T>* t);
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(const T &value);
  void inOrder() const;
  void postOrder() const;
  void find(const T &value) const;
  void remove(const T &value);
}; //

#include "BinarySearchTree.cpp"
#endif