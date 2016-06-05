/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* chase one step at a time */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q) {
            if(p == q) return true;
            p = p->next;
            q = q->next;
            if(!q) break;
            q = q->next;
        }
        return false;
    }
};