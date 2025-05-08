#include "Graph.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool Graph::loadCityInformation(const char* fileName) {
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
  for (int i = 0; i < cityIndices.size(); i++) {
    Connectivity[cityIndices[i]].insert(cityIndices[i + 1]);
  }
}

void Graph::Print() {
  map<int, set<int>>::iterator it;
  set<int>::iterator it2;
  for (it = Connectivity.begin(); it != Connectivity.end(); it++) {
    cout << "Key: " << it->first << " ";
    for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      cout << "Value: " << *it2 << " ";
    }
  }
}
void Graph::showConnectivity(int a) {}

// OLD PRINT OUT FOR CITY INFO
// for (int i = 0; i < cityCoordinates.size(); i++) {
//   cout << cityCoordinates[i].getX() << " " << cityCoordinates[i].getY() <<
//   " "
//        << cityCoordinates[i].getZ() << endl;
// }
// for (int i = 0; i < cityIndices.size(); i++) {
//   cout << cityIndices[i] << " ";
// }