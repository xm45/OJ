class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> num(len+2,0);
        for(int i = 0 ; i < len; i ++)
            num[i+1] = nums[i];
        num[0] = num[len+1] = 1;
        vector<vector<int>> dp(len+2,vector<int>(len+2, 0));
        for(int l = 2; l <= len+1; l ++)
            for(int i = 0;  i<= len+1 - l; i ++) {
                int j = i + l;
                for(int k = i+1; k < j; k ++)
                    dp[i][j] = max(dp[i][j], num[i]*num[k]*num[j] + dp[i][k] + dp[k][j]);
                //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
        return dp[0][len+1];
    }
};