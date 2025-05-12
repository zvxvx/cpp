/*
Assignment 4
Programmer: Greg Pappas
Compiler: g++
*/
#include "Graph.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool Graph::loadCityInformation(const char *fileName) {
  ifstream file(fileName);
  if (!file.is_open()) {
    cerr << "Error opening file!";
    return false;
  }
  string line;

  while (getline(file, line)) {
    istringstream iss(line);

    char p;
    double x, y, z;
    int d, e, f;

    if (line[0] == 'p') {
      if (iss >> p >> x >> y >> z) {
        cityCoordinates.push_back(Point3D(x, y, z));
      }
    } else if (line[0] == 'c') {
      if (iss >> p >> d >> e >> f) {
        cityIndices.push_back(d);
        cityIndices.push_back(e);
        cityIndices.push_back(f);
      }
    }
  }
  file.close();
  return true;
}

void Graph::Generate() {
  for (int i = 0; i < cityIndices.size(); i += 3) {
    Connectivity[cityIndices[i]].insert(cityIndices[i + 1]);
    Connectivity[cityIndices[i]].insert(cityIndices[i + 2]);
    Connectivity[cityIndices[i + 1]].insert(cityIndices[i]);
    Connectivity[cityIndices[i + 1]].insert(cityIndices[i + 2]);
    Connectivity[cityIndices[i + 2]].insert(cityIndices[i]);
    Connectivity[cityIndices[i + 2]].insert(cityIndices[i + 1]);
  }
}

void Graph::Print() {
  cout << "Printing information for all cities:" << endl;
  map<int, set<int>>::iterator it;
  set<int>::iterator it2;
  for (it = Connectivity.begin(); it != Connectivity.end(); it++) {
    cout << "[" << it->first << "] ";
    for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      cout << *it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void Graph::showConnectivity(int a) {
  double x1, y1, z1;
  map<int, set<int>>::iterator it;

  double x = cityCoordinates[a].getX();
  double y = cityCoordinates[a].getY();
  double z = cityCoordinates[a].getZ();

  Point3D first = Point3D(x, y, z);

  cout << "Showing Connectivity for Node " << a << ": " << endl;

  for (auto it = Connectivity.find(a)->second.begin();
       it != Connectivity.find(a)->second.end(); it++) {
    x1 = cityCoordinates[*it].getX();
    y1 = cityCoordinates[*it].getY();
    z1 = cityCoordinates[*it].getZ();

    Point3D second = Point3D(x1, y1, z1);

    double result = sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y)) +
                         ((z1 - z) * (z1 - z)));
    cout << "[" << a << "-" << *it << "]: " << result << endl;
    ;
  }
  cout << endl;
}
