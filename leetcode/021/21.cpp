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
        ListNode *head = NULL;
        ListNode *now = NULL;
        while(l1 != NULL || l2 != NULL)
        {
            int v;
            if(l1 != NULL && (l2 == NULL || l1->val < l2->val))
            {
                v = l1->val;
                l1 = l1->next;
            }
            else
            {
                v = l2->val;
                l2 = l2->next;
            }
            if(head == NULL)
            {
                head = new ListNode(v);
                now = head;
            }
            else
            {
                now->next = new ListNode(v);
                now = now->next;
            }
        }
        return head;
    }
};