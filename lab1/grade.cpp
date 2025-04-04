#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int numOfStudents(int n) {
  while (n < 2) {
    cout << "Please enter the number of students: ";
    while (!(cin >> n) || cin.get() != '\n') {
      cerr << "Please enter a valid number of students: ";
      cin.clear();
      cin.ignore(100, '\n');
    }
  }
  return n;
}

vector<double> getGrades(vector<double> v, int n) {
  int i = 0;
  while (i < n) {
    double grade;
    cout << "Enter score for student " << i + 1 << ": ";
    while (!(cin >> grade) || cin.get() != '\n') {
      cerr << "Enter a valid score for the student " << i + 1 << ": ";
      cin.clear();
      cin.ignore(100, '\n');
    }
    if (grade < 0 || grade > 100) {
      cerr << "Score must be 0-100." << endl;
    } else {
      v.push_back(grade);
      i++;
    }
  }
  return v;
}

int main() {
  vector<double> num_vec;
  int i = 0;
  int st_num = 0;
  st_num = numOfStudents(st_num);
  num_vec = getGrades(num_vec, st_num);
  // we use functions to calculate the elements in the double vector
  double total = accumulate(num_vec.begin(), num_vec.end(), 0);
  double max_val = *max_element(num_vec.begin(), num_vec.end());
  double min_val = *min_element(num_vec.begin(), num_vec.end());
  double avg = total / st_num;

  cout << "Average score is: " << avg << endl;
  cout << "Min score is: " << min_val << endl;
  cout << "Max score is: " << max_val << endl;
  return 0;
}
