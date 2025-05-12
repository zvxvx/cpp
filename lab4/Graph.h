/*
Assignment 4
Programmer: Greg Pappas
Compiler: g++
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <vector>

#include "Point3D.h"

class Graph {
 public:
  bool loadCityInformation(const char *filename);
  void Generate();
  void Print();
  void showConnectivity(int a);

 private:
  std::vector<Point3D> cityCoordinates;
  std::vector<int> cityIndices;
  std::map<int, std::set<int>> Connectivity;
};

#endif  // GRAPH_H
