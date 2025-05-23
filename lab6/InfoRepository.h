#ifndef INFOREPOSITORY_H
#define INFOREPOSITORY_H
#include "InfoNode.h"

template <class T, class U, class V>
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
    InfoNode<T, U, V>* next = cur->next;
    delete cur;
    cur = next;
  }
}

template <class T, class U, class V>
void InfoRepository<T, U, V>::addInfo(T t, U u, V v) {
  InfoNode<T, U, V>* node = new InfoNode<T, U, V>(t, u, v, first);
  first = node;
}

template <class T, class U, class V>
void InfoRepository<T, U, V>::printInformation() {
  InfoNode<T, U, V>* temp = first;
  while (temp != nullptr) {
    cout << temp->dataOne << "" << temp->dataTwo << "" << temp->dataThree
         << endl;
    temp = temp->next;
  }
}

#endif