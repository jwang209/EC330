#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  string word, line;
 bool test1 = 0, test2 = 0, test3 = 0;
 int count = 0, num = 0;
 fstream my_file;

 my_file.open("DictionaryTest.txt");
 while(!my_file.eof()) {
   getline(my_file, line);
   num++;
 }
 my_file.close();

 my_file.open("DictionaryTest.txt");
 for (int i = 0; i < num; i++) {   //num on mac, but num - 1 on linux
     getline(my_file, word);
     cout << word << endl;
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
       if(!word.empty()) {
         count++;
       }
     }
     test1 = test2 = test3 = 0;
 }
 my_file.close();
 cout << count;
}
