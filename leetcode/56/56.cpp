/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void pr(vector<Interval> &a){
	for(vector<Interval>::iterator v = a.begin(); v != a.end(); v++)
		printf("%d %d\n",v->start,v->end);
	printf("\n");
}
class Solution {
private:
	static bool cmp(Interval a, Interval b) {
		return a.start<b.start;
	}
	bool inI(int a, int l,int r) {
		if(a >= l and a <= r) {
			return true;
		}
		return false;
	}
	bool Imerge(Interval& a, Interval& b) {
		if(inI(b.start, a.start, a.end)){
			a.end = max(a.end, b.end);
			return true;
		}
		return false;
	}
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans = vector<Interval>();
        for(vector<Interval>::iterator v = intervals.begin(); v != intervals.end(); v++)
        	if(ans.size() == 0 or not Imerge(*(ans.end()-1), *v)){
        		ans.push_back(*v);
        	}
        return ans;
    }
};
int main(){
	vector<Interval> a;
	a.push_back(Interval(1,3));
	a.push_back(Interval(2,6));
	a.push_back(Interval(8,10));
	a.push_back(Interval(15,18));
	Solution s;
	vector<Interval> ans = s.merge(a);
	pr(ans);
	return 1;
}
