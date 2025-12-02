#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  ifstream input_file("input.txt");

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return -1;
  }

  vector<pair<long, long>> ranges;
  long start, end;
  char dash;
  char comma;

  while (input_file >> start >> dash >> end) {
      ranges.emplace_back(start, end);
      input_file >> comma;
  }

  // for (auto& range : ranges) {
  //     cout << "Range: " << range.first << " - " << range.second << '\n';
  // }

  long long sum = 0;

  for (const auto& [lo, hi]: ranges) {
      string lo_string = to_string(lo);
      string hi_string = to_string(hi);

      int lo_len = lo_string.length();
      int hi_len = hi_string.length();


    if (lo_len == hi_len && lo_len % 2 == 1 && hi_len % 2 == 1) continue;

    size_t half_len = (lo_len % 2 == 1) ? (lo_len + 1) / 2 : lo_len / 2;

    long half_start = max(1L, (long)pow(10, half_len - 1));
    long half_end = (long)pow(10, hi_len / 2);

    for (long half = half_start; half < half_end; ++half) {
        string s = to_string(half);
        long repeat = stol(s + s);

        if (repeat > hi) break;
        if (repeat >= lo) {
            sum += repeat;
        }
    }
  }

  cout << "Total sum: " << sum << "\n";
  return 0;
}
