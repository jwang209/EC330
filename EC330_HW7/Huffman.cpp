//Jason Wang jaswang@bu.edu and Luke Bacopoulos baco@bu.edu

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>

#include "Huffman.h"

using namespace std;

// Allocate a new node to the tree
Node* getNode(string data, int freq, Node* left, Node* right){
    Node* node = new Node();

    node->data = data;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void Huffman::buildHuffmanTree(char* characters, int* freq, int size) {
	priority_queue<Node*, vector<Node*>, comp> pq;

    char temp;
    string str;

    for(int i = 1; i < size; i++){
      if(freq[i-1] == freq[i]){
        temp = characters[i-1];
        characters[i-1] = characters[i];
        characters[i] = temp;
      }
    }

    unordered_map<char, int> fre;
    for (int i = 0; i < size; i++) {
      fre[characters[i]] = freq[i];
      chars.push_back(characters[i]);
    }

    for (auto pair: fre) {
      string s(1,pair.first);
      pq.push(getNode(s, pair.second, nullptr, nullptr));
    }


    while (pq.size() != 1) {
      Node *left = pq.top(); pq.pop();
      Node *right = pq.top(); pq.pop();

      int sum = left->freq + right->freq;
      str = left->data + right->data;
      pq.push(getNode(str, sum, left, right));
    }

    this->root = pq.top(); // variable root stores a pointer which points to the Huffman Tree's root
    this->pq = pq;
    this->size = size;
}

void Huffman::printCodes(){
	cout << "Huffman Code  Character" << endl;
	cout << "------------------------" << endl;

	Node *temp = this->root;
	for(int x = size - 1; x >= 0; x--){
		temp = this->root;
		string s = string(1,this->chars[x]);
		string huff = "";

		while(s != temp->data){
			if(s == temp->left->data){
				huff = huff + "0";
				cout << huff << "\t \t" << s << endl;
        matches.insert({ huff, this->chars[x] });
				break;
			}
			else if(s == temp->right->data){
				huff = huff + "1";
				cout << huff << "\t \t" << s << endl;
        matches.insert({ huff, this->chars[x] });
				break;
			}
			else if(temp->left->data.find(s) != string::npos){
				temp = temp->left;
				huff = huff + "0";
			}
			else if(temp->right->data.find(s) != string::npos){
				temp = temp->right;
				huff = huff + "1";
			}
		}
	}
}

void Huffman::decodeText(string my_file){
    multimap <string, char> :: iterator itr;
    ifstream file(my_file);
    string line;
    getline(file, line);
    string temp = "";
    cout << endl;
    cout << "The decoded text is: ";
    for (int i = 0; i < line.length(); i++){
        temp = temp + line[i];
        for (itr = matches.begin(); itr != matches.end(); ++itr)
        {
            if(temp == itr->first){
                cout << itr->second;
                temp = "";
            }
        }
    }
    cout << endl;
}
