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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        int l = 0;
        ListNode *l1n = NULL,*l2n = NULL;
        if(l1 != NULL)
        {
            l += l1->val;
            l1n = l1->next;
        }
        if(l2 != NULL)
        {
            l += l2->val;
            l2n = l2->next;
        }
        if(l >= 10)
            if(l1n == NULL)
                l1n = new ListNode(l/10);
            else
                l1n->val += l/10;
        ListNode *p = new ListNode(l%10);
        p->next = addTwoNumbers(l1n, l2n);
        return p;
    }
};