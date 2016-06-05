#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int d;
	Node* left;
	Node* right;
};

#define MAX_Node 20

void construct_Tree(Node* pt, int n, int* p, int len) {
	if (2 * n + 1 >= len) return;
	if (p[2 * n + 1]) {
		pt->left = new Node;
		pt->left->left= NULL; //pay attenton to initialization
		pt->left->right = NULL;
		construct_Tree(pt->left, 2*n + 1, p, len);
	}
	if (p[2 * n + 2]) {
		pt->right = new Node;
		pt->right->left = NULL;
		pt->right->right = NULL;
		construct_Tree(pt->right, 2*n + 2, p, len);
	}
}

int cal_Height(Node* pt) {
	int h = 0;
	queue<Node*> q;
	q.push(pt);
	while (!q.empty()) {
		Node* p = q.front();
		q.pop();
		Node* pl = p->left, *pr = p->right;
		int temp = p->d + 1;
		if (pl) {
			q.push(pl);
			pl->d = temp;
			h = temp;
		}
		if (pr) {
			q.push(pr);
			pr->d = temp;
			h = temp;
		}
	}
	return h;
}

int main() {
	int n; //node num
	cout << "enter n: ";
	cin >> n;
	int* p = new int[n];

	cout << "enter 0/1 for p[n]: ";
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	Node* pt = new Node;
	pt->d = 0;
	construct_Tree(pt, 0, p, n);

	int h = cal_Height(pt);
	cout << "Height: " << h << endl;
	return 0;
}