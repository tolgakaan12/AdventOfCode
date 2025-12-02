#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

  long int count = 0;
  const int modulo = 100;
  int dial = 50;
  long int distance = 0;

  ifstream input_file("input.txt");

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return -1;
  }

  string line;

  while (getline(input_file, line)) {
    if (line.empty()) continue;

    char direction_char = line[0];
    string magnitude_str = line.substr(1);

    distance = stoi(magnitude_str);

    if (direction_char == 'R') {
        dial += distance;
        if (dial >= modulo) {
            count += dial / 100;
        }
        dial %= modulo;
    }
    else {
        int prev_dial = dial;
        count += (distance / 100);
        distance %= 100;
        dial += (modulo - distance);
        if (dial <= modulo && prev_dial != 0) {
            ++count;
        }
        dial %= modulo;
    }
  }
  cout << "Total count: " << count << "\n";
  return 0;
}
