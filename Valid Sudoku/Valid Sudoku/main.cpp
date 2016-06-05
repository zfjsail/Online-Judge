#include <unordered_map>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<char, int> ht[27];
		int size = 9;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				char ch = board[i][j];
				if (ch == '.') continue;
				int x = i;
				int y = 9 + j;
				int z = 18 + 3 * (i / 3) + (j / 3);

				if (ht[x].count(ch) > 0) return false;
				else ht[x][ch] = 1;

				if (ht[y].count(ch) > 0) return false;
				else ht[y][ch] = 1;

				if (ht[z].count(ch) > 0) return false;
				else ht[z][ch] = 1;
			}
		}
		return true;
	}
};

int main() {
	vector<vector<char>> b(9);
	char* str = new char[10];
	str = ".87654321";
	for (int i = 0; i < 9; i++) b[i].resize(9);
	for (int i = 0; i < 9; i++) b[0][i] = str[i];
	str = "2........";
	for (int i = 0; i < 9; i++) b[1][i] = str[i];
	str = "3........";
	for (int i = 0; i < 9; i++) b[2][i] = str[i];
	str = "4........";
	for (int i = 0; i < 9; i++) b[3][i] = str[i];
	str = "5........";
	for (int i = 0; i < 9; i++) b[4][i] = str[i];
	str = "6........";
	for (int i = 0; i < 9; i++) b[5][i] = str[i];
	str = "7........";
	for (int i = 0; i < 9; i++) b[6][i] = str[i];
	str = "8........";
	for (int i = 0; i < 9; i++) b[7][i] = str[i];
	str = "9........";
	for (int i = 0; i < 9; i++) b[8][i] = str[i];
	Solution s;
	cout << s.isValidSudoku(b) << endl;
	return 0;
}