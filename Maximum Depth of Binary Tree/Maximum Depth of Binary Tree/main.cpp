
#include <cstdlib>
#include<iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


struct Node {
	TreeNode* t;
	struct Node* next;
	Node() { next = NULL; }
};

class Queue {
private:
	Node* head;
	Node* tail;
public:
	Queue() {
		head = tail = NULL;
	}
	bool empty() {
		return head == NULL;
	}
	void push(TreeNode* t) {
		Node* p = new Node;
		if (!head) {
			head = p;
			head->t = t;
			tail = p;
		}
		else {
			tail->next = p;
			p->t = t;
			tail = p;
		}
	}
	TreeNode* front() {
		return head->t;
	}
	void pop() {
		Node* p = head;
		head = head->next;
		delete p;
	}

};


class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		Queue q;
		root->val = 1;
		q.push(root);
		int h = 1;
		while (!q.empty()) {
			TreeNode* frt = q.front();
			h = frt->val;
			q.pop();
			TreeNode* l = frt->left;
			TreeNode* r = frt->right;
			if (l) {
				l->val = h + 1;
				q.push(l);
			}
			if (r) {
				r->val = h + 1;
				q.push(r);
			}
		}
		return h;
	}
};

int main() {
	TreeNode* p = new TreeNode(0);
	p->left = new TreeNode(0);
	p->right = new TreeNode(0);
	Solution* s = new Solution();
	cout << s->maxDepth(p) << endl;
	return 0;
}