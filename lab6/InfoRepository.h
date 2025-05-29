/**
 * Author: Greg Pappas
 * Assignment: Lab 6
 * Compiler: g++
 */
#ifndef INFOREPOSITORY_H
#define INFOREPOSITORY_H
#include <iomanip>

#include "InfoNode.h"

template <typename T, typename U, typename V>
class InfoRepository {
 private:
  InfoNode<T, U, V>* first;
  std::string iName;

 public:
  InfoRepository(std::string name) : first(nullptr), iName(name) {}
  ~InfoRepository();
  void addInfo(T t, U u, V v);
  bool isEmpty();
  void printInformation();
  void retrieveInfoNode(const T& t);
};

template <typename T, typename U, typename V>
InfoRepository<T, U, V>::~InfoRepository() {
  InfoNode<T, U, V>* cur = first;
  while (cur != nullptr) {
    delete cur;
    cur = cur->next;
  }
}

template <typename T, typename U, typename V>
void InfoRepository<T, U, V>::addInfo(T t, U u, V v) {
  InfoNode<T, U, V>* node = new InfoNode<T, U, V>(t, u, v, first);
  first = node;
}

template <typename T, typename U, typename V>
bool InfoRepository<T, U, V>::isEmpty() {
  if (first == nullptr) {
    return true;
  }
  return false;
}

template <typename T, typename U, typename V>
void InfoRepository<T, U, V>::printInformation() {
  InfoNode<T, U, V>* cur = first;
  cout << "Printing " << this->iName << " info....." << endl;
  cout << endl;
  while (cur != nullptr) {
    cout << left << setw(15) << cur->dataOne << setw(30) << cur->dataTwo
         << right << fixed << setprecision(2) << cur->dataThree << endl;
    cur = cur->next;
  }
  cout << endl;
}

template <typename T, typename U, typename V>
void InfoRepository<T, U, V>::retrieveInfoNode(const T& t) {
  InfoNode<T, U, V>* cur = first;
  bool idFound = false;
  cout << "Retrieving Node with id " << t << " from the database....." << endl;
  while (cur != nullptr) {
    if (cur->dataOne == t) {
      cout << "Node with id " << t << " was found in the database." << endl;
      idFound = true;
      break;
    }
    cur = cur->next;
  }
  if (!idFound) {
    cout << "No Node with id " << t << " exists in the list." << endl;
  } else {
    cout << endl;
    cout << "Here is the information....." << endl;
    cout << left << setw(15) << cur->dataOne << setw(30) << cur->dataTwo
         << right << fixed << setprecision(2) << cur->dataThree << endl;
  }
  cout << endl;
}

#endif