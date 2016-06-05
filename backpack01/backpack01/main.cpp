#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_M 100000
#define MAX_N 500

int v[MAX_M + 1][MAX_N + 1];

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int* need = new int[n];
	int* value = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> need[i];
		cin >> value[i];
	}
	for (int i = 0; i <= m; i++) {
		v[i][0] = 0;
	}
	for (int i = 0; i <= n; i++) {
		v[0][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < need[j - 1]) v[i][j] = v[i][j-1];
			else {
				int max = v[i - need[j - 1]][j - 1] + value[j - 1];
				if (max < v[i][j - 1]) max = v[i][j - 1];
				v[i][j] = max;
			}
		}
	}
	cout << v[m][n] << endl;
	return 0;
}