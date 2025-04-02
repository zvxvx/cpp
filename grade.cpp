#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int st_num;
  double min_val;
  double max_val;
  double avg;
  double total = 0;
  vector<double> num_vec;
  bool correct = false;

  while (st_num < 2) {
    cout << "Please enter the number of students: " << endl;
    while (!(cin >> st_num)) {
      cerr << "Please enter a valid number of students: " << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
  }

  for (int i = 0; i < st_num; i++) {
    double grade;
    cout << "Enter score for student " << i + 1 << ": ";
    cin >> grade;
    while (grade < 0 || grade > 100) {
      cout << "Enter a valid score for the student " << i + 1 << ": ";
      cin >> grade;
    }
    total += grade;
    num_vec.push_back(grade);
  }

  avg = total / st_num;
  max_val = *max_element(num_vec.begin(), num_vec.end());
  min_val = *min_element(num_vec.begin(), num_vec.end());

  // cout << "[";
  // for (int i = 0; i < st_num; i++) {
  //   if (i == st_num - 1) {
  //     cout << num_vec[i];
  //   } else {
  //     cout << num_vec[i] << ", ";
  //   }
  // }
  // cout << "]" << endl;

  cout << "Average score is: " << avg << endl;
  cout << "Min score is: " << min_val << endl;
  cout << "Max score is: " << max_val << endl;
  return 0;
}
