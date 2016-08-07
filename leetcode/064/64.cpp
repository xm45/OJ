class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m?grid[0].size():0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                if(i)
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if(j)
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
                if(!i && !j)
                    dp[i][j] = grid[i][j];
            }
        return dp[m-1][n-1];
    }
};