#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream input_file("input.txt", ios::ate);

  if (!input_file.is_open()) {
    cerr << "Error: could not open input.txt. ensure it exists in the same dir" << "\n";
    return -1;
  }

  streamsize file_size = input_file.tellg();
  input_file.seekg(0, ios::beg);

  string buffer(file_size, ' ');
  if (!input_file.read(&buffer[0], file_size)) return 1;

  size_t line_end = buffer.find('\n');
  size_t width = (line_end == string::npos) ? buffer.size() : line_end;

  size_t height = 0;
  for (char c : buffer) if ( c == '\n') ++height;
  if (buffer.back() != '\n') ++height; /* handle last line if no \n */

  size_t padded_width = width + 2;
  size_t padded_height = height + 2;

  vector<char> grid(padded_width * padded_height, '.');

  size_t read_pos = 0;

  for (size_t r = 1; r <= height; ++r) {
    for (size_t c = 1; c <= width; ++c) {
      while (read_pos < file_size && (buffer[read_pos] == '\r' || buffer[read_pos] == '\n')) {
        ++read_pos;
      }
      if (read_pos < file_size) {
        grid[r * padded_width + c] = buffer[read_pos++];
      }
    }
  }

  int accessible_count = 0;
  for( size_t r = 1; r <= height; ++r) {
    const char* current_row = &grid[r * padded_width];

    for( size_t c = 1; c <= width; ++c) {
      if (current_row[c] == '@') {
        size_t w = padded_width;
        int neighbours =
          (current_row[c - w - 1] == '@') + (current_row[c - w] == '@') + (current_row[c - w + 1] == '@') +
          (current_row[c - 1]     == '@') +                               (current_row[c + 1]     == '@') +
          (current_row[c + w - 1] == '@') + (current_row[c + w] == '@') + (current_row[c + w + 1] == '@');

        if (neighbours < 4) {
          ++accessible_count;
        }
      }
    }
  }

  cout << "Accessible count: " << accessible_count << "\n";
  return 0;
}
