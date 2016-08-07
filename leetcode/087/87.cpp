class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 != l2)
            return false;
        if(s1 == s2)
            return true;
        vector<vector<vector<int>>> dp(l1,vector<vector<int>>(l1,vector<int>(l1+1,0)));
        return is(0,0,l1,s1,s2,l1,dp);
    }
    bool is(int x, int y, int l, string& s1, string& s2, int& len, vector<vector<vector<int>>> &dp) {
        //cout<<x<<' '<<y<<' '<<l<<endl;
        if(l == 1)
            return s1[x] == s2[y];
        if(dp[x][y][l] != 0)
            return dp[x][y][l] == 1;
        for(int i = 1; i < l; i ++){
            if(is(x,y,i,s1,s2,len,dp) && is(x+i,y+i,l-i,s1,s2,len,dp)) {
                dp[x][y][l] = 1;
                return true;
            }
            if(is(x,y+(l-i),i,s1,s2,len,dp) && is(x+i,y,l-i,s1,s2,len,dp)) {
                dp[x][y][l] = 1;
                return true;
            }
        }
        dp[x][y][l] = 2;
        return false;
    }
};