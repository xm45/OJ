#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	ListNode* merge(ListNode *a, ListNode *b){
		if(a==NULL)
			return b;
		if(b==NULL)
			return a;
		if(a->val > b->val){
			a->next = merge(a->next, b);
			return a;
		}
		else{
			b->next = merge(a, b->next);
			return b;
		}
	}
	inline static bool cmp(ListNode* a, ListNode* b){return(a->val < b->val);}
public:
    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = NULL;
        vector<ListNode*> vlist;
        for(vector<ListNode*>::iterator v = lists.begin();v != lists.end();v++){
        	ListNode *a = *v;
        	while(a != NULL){
        		vlist.push_back(a);
        		a = a->next;
        	}
        }
        sort(vlist.begin(), vlist.end(), cmp);
        for(int i = 0; i < vlist.size(); i++){
        	if(i == vlist.size() - 1)
        		vlist[i]->next = NULL;
        	else
        		vlist[i]->next = vlist[i + 1];
        }
        if(vlist.size())
	        return vlist[0];
	    else
	    	return NULL;
    }
};
int main(){
	vector<ListNode*> a;
	ListNode *b;
	b = new ListNode(1);
	a.push_back(b);
	b = new ListNode(2);
	a.push_back(b);
	b = new ListNode(3);
	a.push_back(b);
	ListNode *r;
	Solution sol;
	r = sol.mergeKLists(a);
	printf("%d", r->val);
	system("pause");
}

