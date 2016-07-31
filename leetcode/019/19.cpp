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
    int remove(ListNode* head,int n)
    {
        if(head == NULL)
            return 0;
        int i = remove(head->next,n);
        if(i == n)
            head->next = head->next->next;
        return i+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(remove(head,n) == n)
            head = head->next;
        return head;
    }
};