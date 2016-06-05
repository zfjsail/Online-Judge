#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
int max_pld_len(char* str, int start, int len, vector<vector<int>> &v) {
	//if (len == 1) return 1;
	if (len == 2) {
		if (str[start] == str[start + 1]) return 2;
		else return 1;
	}
	if (str[start] == str[start + len - 1]) return max_pld_len(str + 1, start + 1, len - 2) + 2;
	else {
		int len1 = max_pld_len(str, start, len - 1);
		int len2 = max_pld_len(str + 1, start + 1, len - 1);
		int max = len1;
		if (len1 < len2) max = len2;
		return max;
	}
}
*/

int main() {
	char* str = new char[1001]();
	cin >> str;
	int len = strlen(str);
	vector<vector<int>> v;
	v.resize(len);
	for (int i = 0; i < len; i++)
		v[i].resize(len);
	for (int i = 0; i < len; i++)
		v[i][i] = 1;
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == str[i + 1])  v[i][i + 1] = 2;
		else v[i][i + 1] = 1;
	}
	for (int i = 3; i <= len; i++) {
		for (int j = 0; j < len + 1 - i; j++) {
			if (str[j] == str[j + i - 1]) {
				v[j][j + i - 1] = 2 + v[j + 1][i + j - 2];
			}
			else {
				int max = v[j][i + j - 2];
				int d = v[j + 1][i + j - 1];
				if (max < d) max = d;
				v[j][i + j - 1] = max;
			}
		}
	}
	cout << v[0][len - 1] << endl;
	return 0;
}