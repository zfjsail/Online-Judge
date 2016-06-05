#include <string>
#include<iostream>
#define ALPHABETS 26
#define CASE 'a'
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;

class TrieNode {
public:
	TrieNode* children[ALPHABETS];
	bool isLeaf;
public:
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}
		isLeaf = false;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* pt = root;
		for (int i = 0; word[i] != '\0'; i++) {
			int off = CHAR_TO_INDEX(word[i]);
			if (pt->children[off] == NULL) {
				pt->children[off] = new TrieNode();
			}
			pt = pt->children[off];
		}
		pt->isLeaf = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		int len = word.length();
		TrieNode* pt = root;
		for (int i = 0; i < len; i++) {
			int off = CHAR_TO_INDEX(word[i]);
			if (!pt->children[off]) return false;
			pt = pt->children[off];
		}
		return pt->isLeaf;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		int len = prefix.length();
		TrieNode* pt = root;
		for (int i = 0; i < len; i++) {
			int off = CHAR_TO_INDEX(prefix[i]);
			if (!pt->children[off]) return false;
			pt = pt->children[off];
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
	 Trie trie;
	 trie.insert("somestring");
	 cout << trie.search("key") << endl;
	 cout << trie.startsWith("some") << endl;
	 return 0;
}