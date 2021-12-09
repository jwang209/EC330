//Jason Wang jaswang@bu.edu and Luke Bacopoulos baco@bu.edu

#ifndef Huffman_h
#define Huffman_h

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>


using namespace std;

struct Node {
  string data;
  int freq;
  Node *left, *right;
};

// Comparison in order to min heap
struct comp {
  bool operator()(Node* l, Node* r) {
    return l->freq > r->freq;
  }
};

class Huffman {
public:
	Node* root;
	priority_queue <Node*, vector <Node*>, comp> pq;
	vector <char> chars;
  multimap <string, char> matches;
	int size;

	void buildHuffmanTree(char *characters, int *freq, int size);
	void printCodes();
	void decodeText(string my_file);
};

#endif
