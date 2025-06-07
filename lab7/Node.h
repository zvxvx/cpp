/**
 * Author: Greg Pappas
 * Compiler: g++
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T>
class Node {
 private:
  T Value;
  weak_ptr<Node<T>> prev;
  shared_ptr<Node<T>> next;

 public:
  Node<T>(T val) : Value{val} {}

  ~Node<T>() { cout << "Deleting node with a value " << Value << endl; }

  T getValue() { return Value; };

  void setValue(T val) { Value = val; }

  shared_ptr<Node<T>> getNext() { return this->next; };

  shared_ptr<Node<T>> getPrevious() { return this->prev.lock(); };

  void setNext(shared_ptr<Node<T>> nextPtr) { this->next = nextPtr; };

  void setPrevious(weak_ptr<Node<T>> previousPtr) { this->prev = previousPtr; };

  void PrintForward(shared_ptr<Node<T>> start) {
    shared_ptr<Node<T>> temp = start;

    while (temp) {
      cout << temp->getValue() << "-> ";
      temp = temp->getNext();
    }
    cout << endl;
  }

  void PrintReverse(weak_ptr<Node<T>> end) {
    shared_ptr<Node<T>> temp = end.lock();
    while (temp) {
      cout << "<-" << temp->getValue() << " ";
      temp = temp->getPrevious();
    }
    cout << endl;
  }
};

#endif
