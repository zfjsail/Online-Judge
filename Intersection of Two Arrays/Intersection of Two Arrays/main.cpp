#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
private:
	void qsort(vector<int>& a, int s, int t) {
		if (s >= t) return;
		int i = s, j = t;
		int pivot = a[i];
		while (i < j) {
			while (a[j] > pivot && i < j) { j--; }
			if(i < j) a[i++] = a[j];
			while (a[i] < pivot && i < j) { i++; }
			if(i < j) a[j--] = a[i];
		}
		a[i] = pivot;
		qsort(a, s, i - 1);
		qsort(a, i + 1, t);
	}

	bool binary_search(vector<int>& a, int d) {
		int i = 0, j = a.size() - 1;
		int mid;
		while (i <= j) {
			mid = (i + j) / 2;
			if (a[mid] == d) return true;
			else if (a[mid] < d) i = mid + 1;
			else j = mid - 1;
		}
		return false;
	}
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> sr;
		set<int>::iterator it;
		qsort(nums1, 0, nums1.size() - 1);
		for (int i = 0; i < nums2.size(); i++) {
			int d = nums2[i];
			if (binary_search(nums1, d)) sr.insert(d);
		}
		vector<int> vr;
		for (it = sr.begin(); it != sr.end(); ++it) {
			vr.push_back(*it);
		}
		return vr;
	}
};

int main() {
	Solution s;
	int aa[5] = { 1,2,2,1,3 };
	int bb[3] = { 2,2,3 };
	vector<int> a(aa, aa + sizeof(aa) / sizeof(int));
	vector<int> b(bb, bb + sizeof(bb) / sizeof(int));
	vector<int> c = s.intersection(a, b);
	return 0;
}