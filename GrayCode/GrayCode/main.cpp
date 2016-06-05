#include <iostream>
using namespace std;

#define N 4
#define M 1 << N

void gen_gray_code(int a[][N], int n) {
	if (n == 1) {
		a[0][0] = 0;
		a[1][0] = 1;
		return;
	}
	gen_gray_code(a, n - 1);
	for (int i = (1 << (n - 1)); i < (1 << n); i++) { //note: recurrence formula
		a[i][n - 1] = 1;
		for (int j = 0; j < n - 1; j++)
			a[i][j] = a[(1 << n) - 1 - i][j];
	}
}

void GrayWrapper(int a[][N], int n) {
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 0;
		}
	}
	gen_gray_code(a, n);
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < N; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int a[M][N]; //pay attention to the size first
	GrayWrapper(a, N);
	return 0;
}
