class Solution {
public:
    bool dfs(int x, int y, int l, int& n, int& m, vector<vector<char>>& board, string& word, int& len, vector<vector<bool>>& h) {
        if(board[x][y] != word[l])
            return false;
        if(l == len-1)
            return true;
        h[x][y] = 1;
        for(int i = 0; i < 4; i++)
        {
            int dx = (i%2) * ((i/2)*2 -1);
            int dy = !(i%2) * ((i/2)*2 -1);
            int nx = x+dx, ny = y+dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                char nc = board[nx][ny];
                if(h[nx][ny] == 0) {
                    if(dfs(nx,ny,l+1, n,m,board,word,len,h))
                        return true;
                }
            }
        }
        h[x][y] =0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = n?board[0].size():0;
        vector<vector<bool>> h(n,vector<bool>(m,false));
        int len = word.length();
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j++)
                if(dfs(i,j,0, n,m,board,word,len,h))
                    return true;
        return false;
    }
};