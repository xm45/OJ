class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ret(k,0);
        dfs(0,k,n,ans,ret, 0);
        return ans;
    }
    void dfs(int now, int k, int n, vector<vector<int>> &ans, vector<int> &ret, int top) {
        if(top == k){
            ans.push_back(ret);
            return;
        }
        if(now == n)
            return;
        //cout<<now<<endl;
        if(n - now > k - top)
            dfs(now+1, k, n, ans, ret, top);
        ret[top] = now+1;
        dfs(now+1, k, n, ans, ret, top+1);
        ret[top] = 0;
    }
};