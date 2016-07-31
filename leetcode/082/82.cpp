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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* ans = NULL;
        ListNode* now = NULL;
        int val = head->val - 1;
        int is = 1;
        while(head) {
            if(head->val == val) {
                is = 1;
            }
            else {
                if(is == 0) {
                    if(ans == NULL) {
                        ans = new ListNode(val);
                        now = ans;
                    }
                    else {
                        now->next = new ListNode(val);
                        now = now->next;
                    }
                }
                val = head->val;
                is = 0;
            }
            head = head->next;
        }
        if(is == 0) {
            if(ans == NULL) {
                ans = new ListNode(val);
                now = ans;
            }
            else {
                now->next = new ListNode(val);
                now = now->next;
            }
        }
        return ans;
    }
};