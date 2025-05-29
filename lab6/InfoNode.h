/**
 * Author: Greg Pappas
 * Assignment: Lab 6
 * Compiler: g++
 */
#ifndef INFONODE_H
#define INFONODE_H

#include <iostream>
using namespace std;

template <typename T, typename U, typename V>
class InfoRepository;

template <typename T, typename U, typename V>
class InfoNode {
 private:
  T dataOne;
  U dataTwo;
  V dataThree;
  InfoNode* next;  // points to next node in the list

  friend class InfoRepository<T, U, V>;

 public:
  InfoNode(T& t, U& u, V& v, InfoNode<T, U, V>* p)
      : dataOne(t), dataTwo(u), dataThree(v), next(p) {}
};
#endif