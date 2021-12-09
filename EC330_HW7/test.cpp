#ifndef Huffman_h
#define Huffman_h

#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>


using namespace std;

struct Node
{
    string data;
    int freq;
    Node *left, *right;
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

class Huffman {

public:

	Node* root;
	priority_queue<Node*, vector<Node*>, comp> pq;
	vector<char> chars;
    multimap<string, char> bits;
	int size;

	void buildHuffmanTree(char *characters, int *freq, int size);
	void printCodes();
	void decodeText(string fileName);
};

#endif
