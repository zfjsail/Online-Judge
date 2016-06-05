#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int sz = nums.size();
		vector<int> ac;
		if (sz == 0) return 0;
		if (sz == 1) return nums[0];
		ac.push_back(nums[0]);
		int max = nums[0];
		if (max < nums[1]) max = nums[1]; // ')' is followed by a ';'...
		if (sz == 2) {
			if (nums[0] > nums[1]) {
				return nums[0];
			}
			else {
				return nums[1];
			}
		}
		ac.push_back(max);
		for (int i = 2; i < sz; i++) {
			int a = ac[i - 2] + nums[i];
			int b = ac[i - 1];
			max = b;
			if (a > b) max = a;
			ac.push_back(max);
		}
		return max;
	}
};

int main() {
	int flag;
	cin >> flag;
	vector<int> v;
	while (flag > 0) {
		v.push_back(flag);
		cin >> flag;
	}
	Solution s;
	cout << s.rob(v) << endl;
	return 0;
}