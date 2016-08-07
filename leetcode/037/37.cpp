class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> hash(27, vector<bool>(9, false));
        for(int i = 0; i < 9; i ++)
            for(int j = 0; j < 9; j ++)
                if(board[i][j] != '.'){
                    int val = board[i][j] - '1';
                    hash[i][val] = hash[9 + j][val] = hash[18 + (i/3)*3 + j/3][val] = true;
                }
        dfs(board, hash, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& hash, int x,int y) {
        if(x == 9)
            return true;
        if(board[x][y] == '.') {
            for(int val = 0; val < 9; val ++) {
                if(hash[x][val] || hash[9 + y][val] || hash[18 + (x/3)*3 + y/3][val]) {
                    continue;
                }
                else {
                    hash[x][val] = hash[9 + y][val] = hash[18 + (x/3)*3 + y/3][val] = true;
                    board[x][y] = val + '1';
                    bool ret = dfs(board, hash, x + (y+1)/9, (y+1)%9);
                    if(ret) {
                        return ret;
                    }
                    board[x][y] = '.';
                    hash[x][val] = hash[9 + y][val] = hash[18 + (x/3)*3 + y/3][val] = false;
                }
            }
            return false;
        }
        else {
            return dfs(board, hash, x + (y+1)/9, (y+1)%9);
        }
    }
};