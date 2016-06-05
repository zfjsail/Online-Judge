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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* last = NULL; //remeber initializing pointer
        while(l1 && l2) {
            ListNode* p;
            if(l1->val <= l2->val) {
                p = l1;
                l1 = l1->next;
            }
            else {
                p = l2;
                l2 = l2->next;
            }
            if(!head) {
                head = p;
                last = p;
            }
            else {
                last->next = p;
                last = p;
            }
        }
        if(l1) {
            if(last)last->next = l1; 
            else head = l1; //boundary
        }
        else {
            if(last) last->next = l2;
            else head = l2;
        }
        return head;
    }
};