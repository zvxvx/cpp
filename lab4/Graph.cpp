#include "Graph.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
bool Graph::loadCityInformation(const char* fileName) {
  ifstream file("Terrain.obj");
  if (!file.is_open()) {
    cout << "Error opening file!";
  } else {
    string line;
    istringstream iss(line);
    char p;
    double x, y, z;
    while (getline(file, line)) {
      if (line.find("p") != -1) {
        if (iss >> p >> x >> y >> z) {
          cityCoordinates.push_back(Point3D(x, y, z));
        }
      } else if (line.find("c") != -1) {
        // cityIndices.push_back();
      }
    }
  }
}