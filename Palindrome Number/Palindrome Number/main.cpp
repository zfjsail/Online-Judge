#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int y = 0, z = x;
		while (x) {
			int d = x % 10;
			if (y & 0x40000000) return false;
			y = y * 10 + d;
			x /= 10;
		}
		if (z == y) return true;
		else return false;
	}
};

int main() {
	Solution s;
	cout << s.isPalindrome(121);
	return 0;
}