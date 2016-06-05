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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* pre = NULL;
        ListNode* next;
        ListNode* head1, *head2;
        bool isOdd = true;
        
        /* reverse half list */
        while(q) {
            q = q->next;
            if(q) {
                q = q->next;
            }
            else {
                isOdd = false;
            }
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
            if(isOdd) {
                head2 = p->next;
            }
            else {
                head2 = p;
            }
        }
        head1 = pre;
        
        /* from mid go back and forth */
        while(head1 && head2) {
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};