#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, p, w, h;
		cin >> n >> p >> w >> h;
		int* a = new int[n];
		int s = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			s += a[j];
		}
		int sz = sqrt(p * w * h / (double)s);
		while (1) {
			int ho = w / sz;
			int ve = h / sz;
			int sum = 0;
			int max = ve * p;
			for (int j = 0; j < n; j++) {
				int line = 0;
				if (a[j] % ho == 0) {
					line = a[j] / ho;
				}
				else {
					line = a[j] / ho + 1;
				}
				sum += line;
			}
			if (sum <= max) break;
			sz--;
		}
		cout << sz << endl;
	}
}