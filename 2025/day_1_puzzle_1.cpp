#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split_line(const string& str, char delimiter) {

  vector<string> tokens;
  string token;
  istringstream tokenStream(str);

  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}


int main() {

  int count = 0;

  int modulo = 100;

  int dial = 50;

  ifstream input_file("input.txt");

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return 1;
  }

  string line;

  int line_count = 0;

  while (getline(input_file, line)) {
    ++line_count;
    cout << "processed line: " << line_count << "\n";

    vector<string> entries = split_line(line, '\n');


    for (const string& entry: entries) {

      char direction_char = entry[0];
      int direction_int = 0;

      if (direction_char == 'R') {
        direction_int = +1;
      }
      else {
        direction_int = -1;
      }

      string magnitude_str = entry.substr(1);

      int magnitude_int = stoi(magnitude_str);

      int current = direction_int * magnitude_int;

      dial += current;

      dial = (dial + modulo) % modulo;

      cout << dial << "\n";

      if (dial == 0) {
        ++count;
      }
      
    }
  }
  cout << "Count: " << count << "\n";
  return count;
}
