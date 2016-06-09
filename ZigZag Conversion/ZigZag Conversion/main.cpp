#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int div = 2 * numRows - 2;
		if (div == 0) return s; // may divide 0! 
		int len = s.size();
		int r = len / div;
		int wid, unit_wid = numRows - 1;
		if (len % div <= numRows) {
			wid = unit_wid * r + 1; //  +1 cal carefully not 0
		}
		else {
			wid = unit_wid * (r + 1); //lazy
		}

 		vector<vector<char> > v(numRows, vector<char>(wid, '\0'));

		for (int i = 0; i < len; i++) {
			int rr = i / div;
			int u = i % div, w = rr * unit_wid;
			if (u >= numRows) {
				u = div - u;
				w += (unit_wid - u);
			}
			v[u][w] = s[i];
		}

		string sr;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < wid; j++) {
				char c = v[i][j];
				if (c) sr += c;
			}
		}
		return sr;
	}
};

int main() {
	Solution s;
	string ss = s.convert("abcefgh", 3);
	cout << ss << endl;
	return 0;
}