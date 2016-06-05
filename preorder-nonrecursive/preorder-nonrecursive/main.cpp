#include <stack>
#include<vector>
#include<iostream>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> v;
		TreeNode* p = root;
		if (!p) return v;
		while (1) {
			v.push_back(p->val);
			TreeNode* l = p->left;
			TreeNode* r = p->right;
			if (r) st.push(r);
			if (l) p = l;
			else {
				if (st.empty()) break;
				else {
					p = st.top();
					st.pop();
				}
			}
		}
		return v;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	//TreeNode* r = root->right;
	root->right = new TreeNode(2);
	//r = r->left;
	root->right->left = new TreeNode(3);
	Solution s;
	vector<int> v = s.preorderTraversal(root);
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
	return 0;
}