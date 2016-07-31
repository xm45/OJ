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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *next;
        ListNode *now;
        ListNode *last = NULL;
        ListNode *end = NULL;
        now = head;
        int i = 0;
        while(k-i)
        {
            if(now == NULL)
                return head;
            end = now;
            now = now->next;
            i++;
        }
        last = reverseKGroup(now,k);
        now = head;
        while(now != end)
        {
            next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        if(last != NULL)
            end->next = last;
        return end;
    }
};