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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* q = head->next;
        head->next = NULL;
        while(q) {
            ListNode* p = head;
            head = q;
            q = q->next;
            head->next = p;
        }
        return head;
    }
};