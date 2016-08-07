class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > hash(27, vector<bool>(9, false));
        for(int i = 0; i < 9; i ++)
            for(int j = 0; j < 9; j ++)
                if(board[i][j] != '.'){
                    int val = board[i][j] - '1';
                    if(hash[i][val] || hash[9 + j][val] || hash[18 + (i/3)*3 + j/3][val])
                        return false;
                    hash[i][val] = hash[9 + j][val] = hash[18 + (i/3)*3 + j/3][val] = true;
                }
        return true;
    }
};