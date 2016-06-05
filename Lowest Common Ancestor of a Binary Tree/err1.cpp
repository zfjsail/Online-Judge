/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* tree height constrain the index of node */

struct Node {
    TreeNode* t;
    long long int pos;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        queue<Node*> qt;
        vector<TreeNode*> v;
        vector<long long int> vv;
        Node* pn = new Node;
        pn->t = root;
        pn->pos = 0;
        qt.push(pn);
        v.push_back(root);
        vv.push_back(0);
        long long int left, right;
        while(!qt.empty()) {
            Node* pt = qt.front();
            long long int pos = pt->pos;
            TreeNode* t = pt->t;
            if(t == p) left = pos;
            if(t == q) right = pos;
            qt.pop();
            delete pt;
            TreeNode* l = t->left;
            TreeNode* r = t->right;
            if(l) {
                Node* pn = new Node;
                pn->t = l;
                pn->pos = 2*pos + 1;
                qt.push(pn);
                v.push_back(l);
                vv.push_back(pn->pos);
            }
            if(r) {
                Node* pn = new Node;
                pn->t = r;
                pn->pos = 2*pos + 2;
                qt.push(pn);
                v.push_back(r);
                vv.push_back(pn->pos);
            }
            
        }
        if(left > right) {
            long long int temp = left;
            left = right;
            right = temp;
        }
        while(left != right) {
            right = (right - 1) / 2;
            if(left > right) {
                long long int temp = left;
                left = right;
                right = temp;
            }
        }
        long long int i = 0;
        while(vv[i] != left) {
            i++;
        }
        return v[i];
    }
};