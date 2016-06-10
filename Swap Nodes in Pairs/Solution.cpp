/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = head, *q, *r, *last = NULL;
        head = head->next;
        while(p) {
            q = p->next;
            if(last) {
                if(q)last->next = q;
                else last->next = p;
            }
            if(!q) break;
            r = q->next;
            q->next = p;
            last = p;
            p = r;
        }
        if(!p && last) {
            last->next = NULL;
        }
        return head;
    }
};