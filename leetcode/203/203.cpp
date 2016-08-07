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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tail = head;
        ListNode *ans = NULL;
        ListNode *now = NULL;
        while(tail) {
            if(tail->val != val) {
                if(ans) {
                    now->next = new ListNode(tail->val);
                    now = now->next;
                }
                else {
                    ans = new ListNode(tail->val);
                    now = ans;
                }
            }
            tail = tail->next;
        }
        return ans;
    }
};