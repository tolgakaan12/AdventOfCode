#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int char_to_int(const char c) {
  return c - '0';
}

int main() {

  ifstream input_file("input.txt");

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return -1;
  }

  string line;
  long sum = 0;

  while (getline(input_file, line)) {
    if (line.empty()) continue;

    int dig1 = char_to_int(line[0]);

    int initial_d2 = char_to_int(line[1]);
    int max_joltage = dig1 * 10 + initial_d2;

    int len = line.size();

    for (int i = 2; i < len; ++i) {

      int previous_digit = char_to_int(line[i - 1]);
      dig1 = max(dig1, previous_digit);

      int current_d2 = char_to_int(line[i]);
      int potential_joltage = dig1 * 10 + current_d2;

      max_joltage = max(max_joltage, potential_joltage);
    }

    sum += max_joltage;
  }
  cout << "Sum: " << sum << '\n';
  return 0;
}
