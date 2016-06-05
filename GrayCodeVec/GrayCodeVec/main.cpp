#include <iostream>
#include <vector>
using namespace std;

void gen_gray_code(vector<vector<int>>& v, int n) { //pass by reference
	if (n == 1) {
		v.resize(2);
		v[0].push_back(0);
		v[1].push_back(1);
		return;
	}
	gen_gray_code(v, n - 1);
	int half = 1 << (n - 1);
	v.resize(2 * half);
	for (int i = half; i < 2 * half; i++) {
		v[i] = v[2 * half - 1 - i];
		v[i].push_back(1);
		v[2 * half - 1 - i].push_back(0);
	}
}

void print_vec(vector<vector<int>>& v) {
	int h = v.size(); //+()
	int w = v[0].size();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "input n: ";
	cin >> n;
	vector<vector<int>> v;
	gen_gray_code(v, n);
	print_vec(v);
}