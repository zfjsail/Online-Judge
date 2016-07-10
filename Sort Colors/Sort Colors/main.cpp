#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int le = 0, ri = len - 1;

		while (le < ri && nums[le] == 2 && nums[ri] == 0) {
			swap(nums, le, ri);
			le++;
			ri--;
		}

		for (; le < len; le++) if (nums[le] != 0) break;
		for (; ri >= 0; ri--) if (nums[ri] != 2) break;
		int i = le;

		while (le < ri) {
			if (i < le) i = le;
			while (nums[i] == 1) i++;
			if (i > ri) break;
			if (nums[i] == 0) {
				swap(nums, le, i);
				for (le++; le < len; le++) {
					if (nums[le] != 0) break;
				}
				for (; ri >= 0; ri--) {
					if (nums[ri] != 2) break;
				}
			}
			if (nums[i] == 2) {
				swap(nums, ri, i);
				for (ri--; ri >= 0; ri--) {
					if (nums[ri] != 2) break;
				}
				for (; le < len; le++) {
					if (nums[le] != 0) break;
				}
			}
		}
	}

	void swap(vector<int>& v, int s, int t) {
		int tmp = v[s];
		v[s] = v[t];
		v[t] = tmp;
	}
};

int main() {
	int x[] = { 0,2,1,0,1,2,0,1,1,2,1,1,2,0,1,1,0,2,1,2,1,1,1,2,0 };
	vector<int> v(x, x + sizeof(x) / sizeof(x[0]));
	Solution s;
	s.sortColors(v);
	return 0;
}