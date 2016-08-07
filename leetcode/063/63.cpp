class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = m?obstacleGrid[0].size():0;
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(obstacleGrid[i][j] == 0)
                    if(i == 0 && j == 0)
                        v[i][j] = 1;
                    else if(i == 0)
                        v[i][j] = v[i][j-1];
                    else if(j == 0)
                        v[i][j] = v[i-1][j];
                    else
                        v[i][j] = v[i-1][j] + v[i][j-1];
                else
                    v[i][j] = 0;
        return v[m-1][n-1];
    }
};