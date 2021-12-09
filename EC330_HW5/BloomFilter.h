//Jason Wang jaswang@bu.edu and Luke Bacopoulos

#ifndef BloomFilter_h
#define BloomFilter_h

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class BloomFilter {
public:
	BloomFilter (int length);
	void insert(string item);
	bool exists(string item);
	string output();
	int hash1(string item);
	int hash2(string item);
	vector<bool> my_filter;

protected:
	char *bf;       /** The Bloom filter */
	int len;
};

#endif


BloomFilter::BloomFilter(int length) {
	int counter = 0;
	len = length;
	while (counter != length) {
		my_filter.push_back(0);
		counter++;
	}
}


void BloomFilter::insert(string item) {
	int x = hash1(item);
	my_filter[x] = 1;
	int y = hash2(item);
	my_filter[y] = 1;
}

int BloomFilter::hash1 (string item) {
	int hashVal = 0;
	for (int i = 0; i < item.length(); i++) {
		hashVal = (hashVal * 17) + item[i];
	}
	return hashVal % len;
}

int BloomFilter::hash2(string item) {
	int hashVal = 0;
	for(int i = 0; i < item.length(); i++){
		hashVal = (19*hashVal) +item[i];
	}
	return hashVal % len;
}

bool BloomFilter::exists(string item) {
	int x = hash1(item);
	int y = hash2(item);
	if (my_filter[x] == 1 && my_filter[y] == 1) {
		return true;
	} else {
		return false;
	}
}

string BloomFilter::output() {
	string s;
	for (int i = 0; i < len; i++) {
		if(my_filter[i] == 0) {
			s += "0";
		} else if (my_filter[i] == 1) {
			s += "1";
		} else {
			s += " ";
		}
	}
	return s;
}
