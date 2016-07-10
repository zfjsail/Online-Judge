#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return maxSubArray(nums, 0, nums.size() - 1);
	}

	int maxSubArray(vector<int>& nums, int s, int t) {
		if (s == t) return nums[s];
		int mid = (s + t) / 2;
		int a = maxSubArray(nums, s, mid);
		int b = maxSubArray(nums, mid + 1, t);
		int c;
		int c1 = nums[mid];
		int mx1 = c1;
		for (int i = mid - 1; i >= s; i--) {
			c1 += nums[i];
			if (c1 > mx1) mx1 = c1;
		}
		int c2 = nums[mid + 1];
		int mx2 = c2;
		for (int i = mid + 2; i <= t; i++) {
			c2 += nums[i];
			if (c2 > mx2) mx2 = c2;
		}
		c = mx1 + mx2;
		return max3(a, b, c);
	}

	int max3(int a, int b, int c) {
		int mx = a;
		if (a < b) mx = b;
		if (mx < c) mx = c;
		return mx;
	}
};

/*
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int mxe = 2147483647;
		int len = nums.size();
		int i;
		for (i = 0; i < len; i++) {
			if (nums[i] >= 0) break;
			if (nums[i] > mxe) mxe = nums[i];
		}
		if (i < len) {
			int mx = 0;
			int sum = 0;
			for (int i = 0; i < len; i++) {
				sum += nums[i];
				if (mx < sum) {
					mx = sum;
				}
				else if (sum < 0) {
					sum = 0;
				}
			}
			return mx;
		}
		else {
			return mxe;
		}
	}
};

*/

int main() {
	int x[9] = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> v(x, x + sizeof(x) / sizeof(x[0]));
	Solution s;
	cout << s.maxSubArray(v) << endl;
	return 0;
}