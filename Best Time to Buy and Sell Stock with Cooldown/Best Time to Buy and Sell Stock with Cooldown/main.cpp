#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (0 == len) return 0;
		int left = 0, right = 0;
		int max = 0;
		for (int i = 1; i < len; i++) {
			if (prices[i] < prices[i - 1]) {
				right = i - 1;
				int dif = 0;
				int off = 0;
				bool merge = false;
				if (left <= i - 2 && i + 1 < len && i - 2 >= 0) {
					int dif2 = prices[i + 1] - prices[i];
					int dif1;
					int mx;
					if (dif2 > 0) {
						dif1 = prices[i - 1] - prices[i - 2];
						if (dif1 > 0) {
							if (dif1 > dif2) {
								off = 1;
								mx = dif1;
							}
							else {
								dif = dif1;
								mx = dif2;
							}
						}
					}
					if (dif2 > 0 && dif1 > 0 && left <= i - 2 && prices[i + 1] - prices[i - 2] > mx) {
						merge = true;
					}
				}
				if (!merge) {
					if (right > left) max += ((prices[right] - prices[left]) - dif);
					i += off;
					right = left = i;
				}
				else {
					right = i;
				}
			}
			else {
				right++;
			}
		}
		if (right == len - 1) {
			max += (prices[right] - prices[left]);
		}
		return max;
	}
};

int main() {
	Solution s;
	int n = 13;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		v[i] = d;
	}
	cout << s.maxProfit(v) << endl;
	return 0;
}