#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> v(n);
		v[0] = 1;
		vector<int> idx(3, 0);
		for (int i = 1; i < n; i++) {
			int a = v[idx[0]] * 2;
			int b = v[idx[1]] * 3;
			int c = v[idx[2]] * 5;
			vector<bool> flag(3, false);
			v[i] = min3(a, b, c, flag);
			for (int i = 0; i < 3; i++) {
				if (flag[i]) idx[i]++;
			}
		}
		return v[n - 1];
	}

	int min3(int a, int b, int c, vector<bool>& flag) {
		int mn = a;
		flag[0] = 1;
		if (mn > b) {
			mn = b;
			flag[0] = 0;
			flag[1] = 1;
		}
		else if (mn == b) {
			flag[1] = 1;
		}
		if (mn > c) {
			mn = c;
			flag[0] = flag[1] = 0;
			flag[2] = 1;
		}
		else if (mn == c) {
			flag[2] = 1;
		}
		return mn;
	}
};

int main() {
	Solution s;
	cout << s.nthUglyNumber(10) << endl;
}