#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bpm(vector<vector<int> > &bg, vector<int> &matchL, vector<int> &matchR, vector<int> &seen, int u) {
	int nr = matchR.size();
	for (int i = 0; i < nr; i++) {
		if (bg[u][i]) {
			if (seen[i]) continue;
			seen[i] = 1;

			if (matchR[i] < 0 || bpm(bg, matchL, matchR, seen, matchR[i])) {
				matchL[u] = i;
				matchR[i] = u;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > g(n, vector<int>(n)); //����ͼ�ڽӾ���
	while(1) {
		int s, t;
		cin >> s >> t;
		if (s == -1 && t == -1) break;
		g[s][t] = g[t][s] = 1;
	}
	queue<int> q;
	vector<int> left, right; //����ͼ�����Ҳ�Ķ���
	vector<int> flag(n); //��ʾÿ���������������Ҳ�
	for (int i = 0; i < n; i++) flag[i] = 0;
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0) {
			left.push_back(i);
			flag[i] = -1; //left
			q.push(i);
		}
		while (!q.empty()) {
			int front = q.front();
			int flg = flag[front];
			q.pop();
			for (int j = 0; j < n; j++) {
				if(flag[j] == 0) {
					if (g[front][j] == 1) {
						q.push(j);
						if (flg == -1) { //left
							flag[j] = 1;
							right.push_back(j);
						}
						else { // right
							flag[j] = -1;
							left.push_back(j);
						}
					}
				}
			}
		}
	}
	int nl = left.size(), nr = right.size();
	vector<vector<int> > bg(nl, vector<int>(nr)); //����ͼ����Ϊ�У��Ҳ��Ϊ�е��ڽӾ���
	for (int i = 0; i < nl; i++) {
		for (int j = 0; j < nr; j++) {
			if (g[left[i]][right[j]]) {
				bg[i][j] = 1;
			}
		}
	}
	vector<int> matchL(nl, -1); //��ʾ����ͼÿ������Ҫƥ����Ҳ��
	vector<int> matchR(nr, -1); //��ʾ����ͼÿ���Ҳ��Ҫƥ�������
	vector<int> seen(nr); //��ʾÿ����ÿ���Ҳ���Ƿ񱻷��ʹ�
	for (int i = 0; i < nl; i++) {
		for (int j = 0; j < nr; j++) seen[j] = 0;
		if (matchL[i] == -1) bpm(bg, matchL, matchR, seen, i);
	}
	vector<vector<int> > bm(n, vector<int>(n)); //����ͼ���ƥ����ڽӾ���
	int cnt = 0;
	for (int i = 0; i < nl; i++) {
		int l = left[i];
		if (matchL[i] < 0) continue;
		int r = right[matchL[i]];
		bm[l][r] = bm[r][l] = 1;
		cnt++;
	}
	for (int i = 0; i < n; i++) flag[i] = 0;
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0) {
			for (int j = 0; j < n; j++) {
				if (bm[i][j]) {
					cout << i << " " << j << endl;
					flag[j] = 1;
				}
			}
		}
	}
	return 0;
}
