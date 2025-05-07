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
  // for (int i = 0; i < cityCoordinates.size(); i++) {
  //   cout << cityCoordinates[i].getX() << " " << cityCoordinates[i].getY() <<
  //   " "
  //        << cityCoordinates[i].getZ() << endl;
  // }
  // for (int i = 0; i < cityIndices.size(); i++) {
  //   cout << cityIndices[i] << " ";
  // }
  return true;
}

void Graph::Generate() {

}