#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int sum = nums[0] + nums[1] + nums[2];
		int s = 0, t = 3;
		int min = abs(sum - target);
		int cur = sum;
		for (; t < nums.size();) {
			sum = sum + nums[t] - nums[s];
			t++; s++;
			int d = abs(sum - target);
			if (d < min) {
				min = d;
				cur = sum;
			}
		}
		return sum;
	}
};

int main() {
	int x[4] = { -1, 2, 1, -4 };
	vector<int> v(x, x + sizeof(x) / sizeof(x[0]));
	Solution s;
	cout << s.threeSumClosest(v, 1) << endl;
	return 0;
}