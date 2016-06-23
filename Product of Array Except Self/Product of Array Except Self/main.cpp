#include <vector>
#include <iostream>
using namespace std;

/* better implementaion */
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int p = 1;
		int len = nums.size();
		vector<int> v(len);
		for (int i = 0; i < len; i++) {
			v[i] = p;
			p *= nums[i];
		}
		p = 1;
		for (int i = len - 1; i >= 0; i--) {
			v[i] *= p;
			p *= nums[i];
		}
		return v;
	}
};

/*
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		bool isHasZero = false; // need to handle the special case
		int pos = -1;
		vector<int> v(len);
		int p = 1;
		for (int i = 0; i < len - 1; i++) {
			if (nums[i] == 0) {
				isHasZero = true;
				pos = i;
				break;
			}
			p *= nums[i];
		}
		if (isHasZero) {
			p = 1;
			for (int i = 0; i < len; i++) {
				if (i != pos) p *= nums[i];
			}
			v[pos] = p;
			return v;
		}
		v[len - 1] = p;
		for (int i = len - 2; i >= 0; i--) {
			v[i] = v[i + 1] * nums[i + 1] / nums[i];
		}
		return v;
	}
};
*/

int main() {
	Solution s;
	vector<int> a(2);
	a[0] = 0; a[1] = 0;
	s.productExceptSelf(a);
	return 0;
}