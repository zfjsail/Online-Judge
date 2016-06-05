/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* prefix code ~ trie node */

struct Node {
    TreeNode* t;
    string s;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        queue<Node*> qt;
        Node* pn = new Node;
        pn->t = root;
        pn->s = "";
        qt.push(pn);
        string sl, sr;
        while(!qt.empty()) {
            Node* pn = qt.front();
            TreeNode* t = pn->t;
            string s = pn->s;
            if(t == p) sl = s;
            if(t == q) sr = s;
            qt.pop();
            delete pn;
            TreeNode* l = t->left;
            TreeNode* r = t->right;
            if(l) {
                pn = new Node;
                pn->t = l;
                pn->s = s + '0';
                qt.push(pn);
            }
            if(r) {
                pn = new Node;
                pn->t = r;
                pn->s = s + '1';
                qt.push(pn);
            }
        }
        if(sl[0] != sr[0]) return root;
        TreeNode* pa = root;
        for(int i = 0; sl[i] == sr[i]; i++) {
            if(sl[i] == '0') pa = pa->left;
            else pa = pa->right;
        }
        return pa;
    }
};