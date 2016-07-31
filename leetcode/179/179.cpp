#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;
class Solution {
	static inline bool cmp(string a, string b){return(a + b > b + a);}
public:
    string largestNumber(vector<int>& nums) {
    	vector<string> strs;
        for(vector<int>::iterator v = nums.begin(); v != nums.end(); v++){
        	stringstream ss;
        	string s;
        	ss << *v;
        	ss >> s;
        	strs.push_back(s);
        }
        sort(strs.begin(), strs.end(), cmp);
		string ret = "";
		if(strs[0] == "0")
			return "0";
        for(vector<string>::iterator v = strs.begin(); v != strs.end(); v++)
        	ret += *v;
		return ret;
    }
};
int main(){
	
}
