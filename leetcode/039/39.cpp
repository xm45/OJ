class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ret;
        int len = candidates.size();
        dfs(target,candidates,ans,ret,0,len);
        return ans;
    }
    void dfs(int target, vector<int>& c, vector<vector<int>> &ans, vector<int>& ret, int begin, int& len) {
        if(target == 0) {
            ans.push_back(ret);
            return;
        }
        for(int i = begin; i < len; i ++) {
            if(c[i] > target)
                continue;
            ret.push_back(c[i]);
            dfs(target-c[i], c, ans, ret, i, len);
            ret.pop_back();
        }
    }
};