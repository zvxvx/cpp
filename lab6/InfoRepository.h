#ifndef INFOREPOSITORY_H
#define INFOREPOSITORY_H

template <class T, class U, class V>
class InfoRepository {
 public:
  InfoRepository(std::string name) : first(0), iName(name) {}
  ~InfoRepository();
  void addInfo(T t, U u, V v);
  bool isEmpty();
  void printInformation();
  void retrieveInfoNode(const T& t);

 private:
  InfoNode<T, U, V>* first;
  std::string iName;
};

#endif