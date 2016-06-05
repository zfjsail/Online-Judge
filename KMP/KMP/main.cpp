#include <vector>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int lenh = haystack.size();
		int lenn = needle.size();
		if (lenn == 0) return 0;
		vector<int> t(lenn);

		/* target string len is 1 */
		if (lenn == 1) {
			int i;
			for (i = 0; i < lenh; i++) {
				if (haystack[i] == needle[0]) break;
			}
			if (i < lenh) return i;
			else return -1;
		}

		/* calculate failure function */
		int pos = 2;
		int cnd = 0;
		t[0] = -1, t[1] = 0;
		while (pos < lenn) {
			if (needle[pos - 1] == needle[cnd]) {
				t[pos] = cnd + 1;
				cnd++;
				pos++;
			}
			else if (cnd > 0) {
				cnd = t[cnd];
			}
			else {
				t[pos] = 0;
				pos++;
			}
		}

		int m = 0, i = 0;
		while (m + i < lenh) {
			if (needle[i] == haystack[m + i]) {
				if (i == lenn - 1) return m;
				i++;
			}
			else {
				if (t[i] > -1) {
					m = m + i - t[i];
					i = t[i];
				}
				else {
					i = 0;
					m++;
				}
			}
		}

		return -1;
	}
};