//Jason Wang jaswang@bu.edu and Lake Bacopoulos baco@bu.edu

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

using namespace std;

int fourA() {
  int count = 0, longest = 0;
  fstream my_file;
  char ch;

  my_file.open("BigData.txt");
  while (my_file >> noskipws >> ch) {
    count++;
    if (isspace(ch)) {
      if (count > longest) {
        longest = count - 1;
      }
      count = 0;
    }
  }
  my_file.close();
  return longest;
}

int fourB() {
  int count = 0, pass = 0;
  fstream my_file;
  char ch;
  bool l_test = 0, u_test = 0, digit_test = 0, word_test = 0;

  my_file.open("BigData.txt");
  while (my_file >> noskipws >> ch) {   //on mac, when you run this command, the condition returns false, on linux, it stores ch = EOF
    count++;
    //cout << l_test << u_test << digit_test << word_test << endl;
    if (isspace(ch)) {
      if (l_test == 1 && u_test == 1 && digit_test == 1 && word_test == 1) {
        pass++;
      }
      l_test = 0;
      u_test = 0;
      digit_test = 0;
      word_test = 0;
      count = 0;
      //if (ch == EOF) {
      // break;
      //}
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
  // cout << pass;
  my_file.close();
  return pass;
}

int fourC() {
  string word;
  bool test1 = 0, test2 = 0, test3 = 0;
  int count = 0, num = 0;
  fstream my_file;

  my_file.open("dictionary.txt");
  while(!my_file.eof()) {
    getline(my_file, word);
    //cout << word << endl;
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == 'c' || word[i] == 'C') {
        test1 = 1;
      }
      if (word[i] == 's' || word[i] == 'S') {
        test2 = 1;
      }
      if (word[i] == 'b' || word[i] == 'B') {
        test3 = 1;
      }
    }
    //cout << test1 << test2 << test3 << endl;
    if (test1 == 0 || test2 == 0 || test3 == 0) {
      if (!word.empty()) {
        count++;
      }
    }
    test1 = test2 = test3 = 0;
  }
  my_file.close();
  return count;
}
