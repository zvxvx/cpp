/**
 * Author: Greg Pappas
 * Compiler: g++
 */
#include "Node.h"

void createDoublyLinkedList();

int main() {
  createDoublyLinkedList();

  return 0;
}

void createDoublyLinkedList() {
  shared_ptr<Node<double>> start;
  weak_ptr<Node<double>> end;
  shared_ptr<Node<double>> nd(new Node<double>(2.567));

  start = nd;
  end = nd;

  shared_ptr<Node<double>> nd1(new Node<double>(485.321));

  nd1->setPrevious(end);
  end.lock()->setNext(nd1);
  end = nd1;

  shared_ptr<Node<double>> nd2(new Node<double>(82.34));

  nd2->setPrevious(end);
  end.lock()->setNext(nd2);
  end = nd2;

  start->PrintForward(start);
  nd2->PrintReverse(end);
}