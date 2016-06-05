/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** 
 * know cycle length 
 * then
 * start at the beginning
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* p = head;
        ListNode* q = head->next;
        int len = 0;
        while(q) {
            if(p == q) break;
            len++;
            p = p->next;
            q = q->next;
            if(!q) break;
            q = q->next;
        }
        if(!q) return NULL;
        ListNode* s = head;
        ListNode* t = head;
        for(int i = 0; i <= len; i++)
            t = t->next;
        while(s != t) {
            s = s->next;
            t = t->next;
        }
        return s;
    }
};