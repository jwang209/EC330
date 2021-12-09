// at least one lower case letter, at least one upper case letter, and at least one digit, and is between 8 and 20 characters in length.

#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int main() {
  int count = 0, word = 0, pass = 0;
  fstream my_file;
  char ch;
  bool l_test = 0, u_test = 0, digit_test = 0, word_test = 0;

  my_file.open("TinyDataTest.txt");
  while (my_file >> noskipws >> ch) {
    cout << ch << endl;
    count++;
    cout << l_test << u_test << digit_test << word_test << endl;
    if (isspace(ch) || ch == EOF) {
      if (l_test == 1 && u_test == 1 && digit_test == 1 && word_test == 1) {
        pass++;
      }
      l_test = 0;
      u_test = 0;
      digit_test = 0;
      word_test = 0;
      count = 0;
      if (ch == EOF) {
        break;
      }
    }
    else {
      if (islower(ch)) {
        l_test = 1;
      }
      if (isupper(ch)) {
        u_test = 1;
      }
      if (isdigit(ch)) {
        digit_test = 1;
      }
      if(count <= 20 && count >=8) {
        word_test = 1;
      }
      if (count > 20) {
        word_test = 0;
      }
    }
  }
  cout << pass;
  my_file.close();
}
