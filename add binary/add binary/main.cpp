#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string r("");
		int carry = 0;
		auto ait = a.rbegin(), bit = b.rbegin();
		for (; ait != a.rend() && bit != b.rend(); ++ait, ++bit) {
			if (carry == 0) {
				if (*ait != *bit) {
					r = "1" + r;
				}
				else if (*ait == '0') {
					r = "0" + r;
				}
				else {
					r = "0" + r;
					carry = 1;
				}
			}
			else {
				if (*ait != *bit) {
					r = "0" + r;
				}
				else if (*ait == '0') {
					r = "1" + r;
					carry = 0;
				}
				else {
					r = "1" + r;
				}
			}
		}
		if (ait != a.rend()) { // a is long
			if (carry == 0) {
				for (; ait != a.rend(); ++ait) {
					r = *ait + r;
				}
			}
			else {
				for (; ait != a.rend(); ++ait) {
					if (carry) {
						if (*ait == '0') {
							r = "1" + r;
							carry = 0;
						}
						else {
							r = "0" + r;
						}
					}
					else {
						r = *ait + r;
					}
				}
				if (carry) r = "1" + r;
			}
		}
		else if (bit != b.rend()) {
			if (carry == 0) {
				for (; bit != b.rend(); ++bit) {
					r = *bit + r;
				}
			}
			else {
				for (; bit != b.rend(); ++bit) {
					if (carry) {
						if (*bit == '0') {
							r = "1" + r;
							carry = 0;
						}
						else {
							r = "0" + r;
						}
					}
					else {
						r = *bit + r;
					}
				}
				if (carry) r = "1" + r;
			}
		}
		else {
			if (carry) r = "1" + r;
		}
		return r;
	}
};

int main() {
	Solution s;
	cout << s.addBinary("1", "1") << endl;
	return 0;
}