#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
  ifstream input_file("input.txt");

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return -1;
  }

  vector<pair<long long, long long>> ranges;
  long long start, end;
  char dash, comma;

  while (input_file >> start >> dash >> end) {
    ranges.emplace_back(start, end);
    input_file >> comma;
  }

  long long sum = 0;

  for (const auto& [lo, hi]: ranges) {
    set <long long> invalid_ids;

    string hi_string = to_string(hi);
    int hi_len = hi_string.length();

    int max_comp_len = hi_len / 2;

    for (int comp_len = 1; comp_len <= max_comp_len; ++comp_len) {

      int comp_start = max(1, (int)pow(10, comp_len - 1));
      int comp_end = (int)pow(10, comp_len);

      // cout << "comp_start: " << comp_start << ", comp_end: " << comp_end << "\n";

      for (int comp = comp_start; comp < comp_end; ++comp) {
        string s = to_string(comp);
        string repeat = s + s;

        while (repeat.length() <= hi_len) {
          long long num = stoll(repeat);
          if (num > hi) break;
          if (num >= lo) {
              invalid_ids.insert(num);
          }
          repeat += s;
        }
      }
    }
    for (long long id : invalid_ids) {
      sum += id;
    }
  }
  cout << "Total sum: " << sum << "\n";
  return 0;
}
