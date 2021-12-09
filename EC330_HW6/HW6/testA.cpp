#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int count = 0, longest = 0;
  fstream my_file;
  char ch;

  my_file.open("TinyDataTest.txt");
  while (my_file >> noskipws >> ch) {
    count++;
    if (isspace(ch)) {
      if (count > longest) {
        longest = count - 1;
      }
      count = 0;
    }
  }
  cout << longest;
  my_file.close();
  return longest;
}
