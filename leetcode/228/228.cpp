class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return vector<string>();
        int now = nums[0];
        int count = 1;
        vector<string> ans;
        for(int i = 1; i < len; i ++) {
            if(now+1 == nums[i]) {
                now++;
                count++;
            }
            else {
                if(count == 1) {
                    stringstream ss;
                    string ret = "";
                    ss<<now;
                    ss>>ret;
                    ans.push_back(ret);
                }
                else {
                    stringstream ss;
                    string ret = "";
                    ss<<now-count+1<<"->"<<now;
                    ss>>ret;
                    ans.push_back(ret);
                }
                now = nums[i];
                count = 1;
            }
        }
        if(count == 1) {
            stringstream ss;
            string ret = "";
            ss<<now;
            ss>>ret;
            ans.push_back(ret);
        }
        else {
            stringstream ss;
            string ret = "";
            ss<<now-count+1<<"->"<<now;
            ss>>ret;
            ans.push_back(ret);
        }
        return ans;
    }
};