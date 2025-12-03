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
  unsigned long long sum = 0;

  while (getline(input_file, line)) {
    if (line.empty()) continue;

    int n = line.size();
    int to_remove = n - 12;

    string stack;

    for (char digit : line) {
      while (
        !stack.empty() &&
        to_remove > 0 &&
        stack.back() < digit) {
          stack.pop_back();
          --to_remove;
        }

      stack.push_back(digit);
    }

    while (stack.size() > 12) {
      stack.pop_back();
    }

    sum += stoull(stack);
  }
  cout << "Sum: " << sum << '\n';
  return 0;
}
