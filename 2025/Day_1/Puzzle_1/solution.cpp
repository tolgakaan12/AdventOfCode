#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {

  ifstream input_file("input.txt");

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return 1;
  }

  int count = 0;
  int modulo = 100;
  int dial = 50;

  string line;
  while (getline(input_file, line)) {
      if (line.empty()) continue;

      char direction_char = line[0];
      int direction_int = (direction_char == 'R') ? +1: -1;

      string magnitude_str = line.substr(1);
      int magnitude_int = stoi(magnitude_str);

      int current = direction_int * magnitude_int;
      dial += current;
      dial = (dial + modulo) % modulo;

      // cout << dial << "\n";

      if (dial == 0) ++count;
    }
  cout << "Count: " << count << "\n";
  return 0;
}
