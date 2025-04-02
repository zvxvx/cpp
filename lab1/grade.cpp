#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int i = 0;
  int st_num = 0;
  double avg;
  double total = 0;
  vector<double> num_vec;

  while (st_num < 2) {
    cout << "Please enter the number of students: ";
    while (!(cin >> st_num) || cin.get() != '\n') {
      cerr << "Please enter a valid number of students: ";
      cin.clear();
      cin.ignore(100, '\n');
    }
  }

  while (i < st_num) {
    double grade;
    cout << "Enter score for student " << i + 1 << ": ";
    while (!(cin >> grade) || cin.get() != '\n') {
      cerr << "Enter a valid score for the student " << i + 1 << ": ";
      cin.clear();
      cin.ignore(100, '\n');
    }
    if (grade < 0 || grade > 100) {
      cerr << "Score must be 0-100." << endl;
      continue;
    }
    total += grade;
    num_vec.push_back(grade);
    i++;
  }

  avg = total / st_num;
  double max_val = *max_element(num_vec.begin(), num_vec.end());
  double min_val = *min_element(num_vec.begin(), num_vec.end());

  cout << "Average score is: " << avg << endl;
  cout << "Min score is: " << min_val << endl;
  cout << "Max score is: " << max_val << endl;
  return 0;
}
