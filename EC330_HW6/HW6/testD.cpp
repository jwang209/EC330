#include <iostream>
#include <fstream>


using namespace std;

int main() {
  string line, word, newstring;
  int count = 0, num = 0, state = 0, passwords = 0;
  int cond1 = 0, cond2 = 0, cond3 = 0, cond4 = 0;
  char ch;
  fstream my_file;

  my_file.open("TinyDataTest.txt");
  while ( my_file >> noskipws >> ch ){
    cout << ch << endl;
    //cout << cond1 << " " << cond2 << " " << cond3 << " " << cond4 << endl;
    count++;
    // one lower, one upper, 8-20 chars, and one number
    if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v' || ch == EOF){
      if (cond1 == 1 && cond2 == 1 && cond3 == 1 && cond4 == 1){ passwords++; }
      cond1 = cond2 = cond3 = cond4 = 0;
      count = 0;
      if(ch == EOF){
        break;
      }
    }
    else{
      if(ch >= 97 && ch <= 122){ cond1 = 1; }
      if (ch >= 65 && ch <= 90){ cond2 = 1; }
      if(count <= 20 && count >= 8){ cond3 = 1; }
      if(ch >= 48 && ch <= 57){ cond4 = 1; }
      if(count > 20) {cond3 = 0;}
    }
  }
  cout << passwords <<endl;
  my_file.close();
}
