#include<iostream>
#include <cstdlib>
#include <string>
#define CASE '0'
using namespace std;

class TrieNode {
public:
	TrieNode* children[2];
	bool isLeaf;
	bool isAllow;
	TrieNode() {
		children[0] = NULL;
		children[1] = NULL;
		isLeaf = false;
	}
};

class Trie {
private: 
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
		root->isAllow = 1; //default is allow
	}
	void insert(string ip, bool isAllow, int maskbit, int order) {
		TrieNode* pt = root;
		for (int i = 0; i < maskbit; i++) {
			int off = ip[i] - CASE;
			if (pt->isLeaf) return; //pay attention to conditions' order
			else if (pt->children[off] == NULL) {
				pt->children[off] = new TrieNode();
			}
			pt = pt->children[off];
		}
		if (pt->isLeaf) return;
		pt->isLeaf = 1;
		pt->isAllow = isAllow;
	}

	bool search(string ip) {
		TrieNode* pt = root;
		bool isAllow = root->isAllow;
		for (int i = 0; i < 32; i++) {
			int off = ip[i] - CASE;
			if (pt->isLeaf) isAllow = pt->isAllow; //pay attention to conditions' order
			if (pt->children[off] == NULL) break;
			pt = pt->children[off];
		}
		return isAllow;
	}
};

string ip2str(char* str2) {
	string sip(str2);
	unsigned ip_4[4];
	char ipstr[33] = "";
	sscanf_s(str2, "%d.%d.%d.%d", &ip_4[0], &ip_4[1], &ip_4[2], &ip_4[3]);
	unsigned ip = (ip_4[0] << 24) + (ip_4[1] << 16) + (ip_4[2] << 8) + ip_4[3];
	//_itoa_s(ip, ipstr, 2); itoa is insecure = =
	for (int i = 0; i < 32; i++) {
		ipstr[i] = ((ip >> (31 - i)) & 1) + CASE;
	}
	return ipstr;
}

int main() {
	int n, m;
	cin >> n >> m;
	Trie trie;
	for (int i = 0; i < n; i++) {
		bool isAllow;
		char ipstr[33] = "";
		int maskbit;
		char str1[10] = "";
		cin >> str1;
		if (str1[0] == 'a') isAllow = true;
		else isAllow = false;
		char str2[30] = "";
		cin >> str2;
		string sip(str2);
		int pos = sip.find("/");
		if (pos == string::npos) {
			maskbit = 32;
		}
		else {
			string str_mask = sip.substr(pos + 1);
			string::size_type sz;
			maskbit = stoi(str_mask, &sz);
			str2[pos] = '\0';
		}
		sip = ip2str(str2);
		trie.insert(sip, isAllow, maskbit, i);
	}
	for (int i = 0; i < m; i++) {
		char str[30] = "";
		cin >> str;
		string sip;
		sip = ip2str(str);
		if (trie.search(sip)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}