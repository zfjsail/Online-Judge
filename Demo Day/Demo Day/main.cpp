#include<vector>
#include<iostream>
using namespace std;

#define right 0
#define down 1

/* there is min function in hiho  O_O*/
int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> maze(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}
	vector<vector<vector<int>>> best(n, vector<vector<int>>(m, vector<int>(2)));
	best[0][0][right] = (maze[0][0] == 'b');
	best[0][0][down] = (1 < m && maze[0][1] != 'b') + (maze[0][0] == 'b');
	for (int i = 1; i < n; i++) {
		best[i][0][down] = best[i - 1][0][down] + (maze[i][0] == 'b');
		best[i][0][right] = best[i - 1][0][down] + (((i + 1) < n) && maze[i + 1][0] != 'b') + (maze[i][0] == 'b');
	}
	for (int j = 1; j < m; j++) {
		best[0][j][right] = best[0][j - 1][right] + (maze[0][j] == 'b');
		best[0][j][down] = best[0][j - 1][right] + (((j + 1) < m) && maze[0][j + 1] != 'b') + (maze[0][j] == 'b');
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			best[i][j][right] = min(best[i][j - 1][right], best[i - 1][j][down] + (i + 1 < n && maze[i + 1][j] != 'b')) + (maze[i][j] == 'b');
			best[i][j][down] = min(best[i - 1][j][down], best[i][j - 1][right] + (j + 1 < m && maze[i][j + 1] != 'b')) + (maze[i][j] == 'b');
		}
	}
	cout << min(best[n - 1][m - 1][down], best[n - 1][m - 1][right]) << endl;
	return 0;
}