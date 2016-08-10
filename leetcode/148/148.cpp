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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return NULL;
        if(!(head->next))
            return head;
        int val = head->val;
        ListNode* now = head;
        ListNode* h1 = NULL;
        ListNode* t1 = NULL;
        ListNode* h2 = NULL;
        ListNode* t2 = NULL;
        ListNode* h3 = NULL;
        ListNode* t3 = NULL;
        while(now) {
            ListNode* last = now;
            now = now->next;
            if(last->val == val){
                if(!h3)
                    h3 = t3 = last;
                else {
                    t3->next = last;
                    t3 = t3->next;
                }
                t3->next = NULL;
            }
            else if(last->val < val){
                if(!h1)
                    h1 = t1 = last;
                else {
                    t1->next = last;
                    t1 = t1->next;
                }
                t1->next = NULL;
            }
            else{
                if(!h2)
                    h2 = t2 = last;
                else {
                    t2->next = last;
                    t2 = t2->next;
                }
                t2->next = NULL;
            }
            //cout<<last->val<<endl;
        }
        //cout<<h1<<' '<<h2<<endl;
        h1 = sortList(h1);
        h2 = sortList(h2);
        t1 = h1;
        if(t1) {
            while(t1->next)
                t1 = t1->next;
            t1->next = h3;
            t3->next = h2;
            return h1;
        }
        else
        {
            t3->next = h2;
            return h3;
        }
    }
};