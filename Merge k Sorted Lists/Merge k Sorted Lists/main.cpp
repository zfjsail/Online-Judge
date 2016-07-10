#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = NULL;
		vector<ListNode*> lh;
		int len = lists.size();
		int hsize = 0;
		for (int i = 0; i < len; i++) {
			if (lists[i]) {
				lh.push_back(lists[i]);
				hsize++;
			}
		}
		if (hsize == 0) return head;
		buildHeap(lh, hsize);

		head = lh[0];
		ListNode* cur = head;
		while (hsize > 0) {
			ListNode* next = cur->next;
			if (next) {
				lh[0] = next;
			}
			else {
				hsize--;
				lh[0] = lh[hsize];
			}
			if (hsize > 0) {
				heapify(lh, 0, hsize);
				cur->next = lh[0];
				cur = lh[0];
			}
		}

		return head;
	}

	void buildHeap(vector<ListNode*>& v, int hsize) {
		for (int i = hsize / 2; i >= 0; i--) {
			heapify(v, i, hsize);
		}
	}

	void heapify(vector<ListNode*>& v, int i, int hsize) {
		int le = 2 * i + 1;
		int ri = le + 1;
		int smallest = i;
		if (le < hsize && v[le]->val < v[i]->val) {
			smallest = le;
		}
		if (ri < hsize && v[ri]->val < v[smallest]->val) {
			smallest = ri;
		}
		if (smallest != i) {
			swap(v, smallest, i);
			heapify(v, smallest, hsize);
		}
	}

	void swap(vector<ListNode*>& v, int i, int j) {
		ListNode* tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}
};

int main() {
	vector<ListNode*> v(4);
	int x1[8] = { -8,-7,-6,-3,-2,-2,0,3 };
	vector<int> v1(x1, x1 + sizeof(x1) / sizeof(x1[0]));
	ListNode* p = new ListNode(x1[0]);
	v[0] = p;
	for (int i = 1; i < 8; i++) {
		ListNode* q = new ListNode(x1[i]);
		p->next = q;
		p = q;
	}
	int x2[] = { -10,-6,-4,-4,-4,-2,-1,4 };
	vector<int> v2(x2, x2 + sizeof(x2) / sizeof(x2[0]));
	p = new ListNode(x2[0]);
	v[1] = p;
	for (int i = 1; i < 8; i++) {
		ListNode* q = new ListNode(x2[i]);
		p->next = q;
		p = q;
	}
	int x3[] = { -10,-9,-8,-8,-6 };
	vector<int> v3(x3, x3 + sizeof(x3) / sizeof(x3[0]));
	p = new ListNode(x3[0]);
	v[2] = p;
	for (int i = 1; i < 5; i++) {
		ListNode* q = new ListNode(x3[i]);
		p->next = q;
		p = q;
	}
	int x4[] = { -10,0,4 };
	vector<int> v4(x4, x4 + sizeof(x4) / sizeof(x4[0]));
	p = new ListNode(x4[0]);
	v[3] = p;
	for (int i = 1; i < 3; i++) {
		ListNode* q = new ListNode(x4[i]);
		p->next = q;
		p = q;
	}
	Solution s;
	s.mergeKLists(v);
	return 0;
}