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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        int i;
        for(i = 0; i < n + 1; i++) {
            if(!q) break;
            q = q->next;
        }
        if(i < n + 1) { //del head
            head = head->next;
            return head;
        }
        while(q) {
            p = p->next;
            q = q->next;
        }
        q = p->next->next;
        p->next = q;
        return head;
    }
};