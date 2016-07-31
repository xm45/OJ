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
        if(head == NULL)
            return NULL;
        ListNode* next = head->next;
        if(next == NULL)
            return head;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};