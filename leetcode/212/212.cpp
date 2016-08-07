class Solution {
public:
    struct Trie{
        int count;
        Trie* next[26];
        bool isEnd;
        Trie():count(0),isEnd(false){
            memset(next,0,sizeof(next));
        };
    };
    void makeTrie(string& word, Trie* trie){
        int len = word.length();
        Trie* now = trie;
        for(int i = 0; i < len; i ++) {
            if(now->next[word[i]-'a']){
                now = now->next[word[i]-'a'];
            }
            else{
                now->next[word[i]-'a'] = new Trie();
                now = now->next[word[i]-'a'];
            }
            now->count ++;
        }
        now->isEnd = 1;
    }
    void dfs(int x, int y, Trie* now, int &n, int &m, vector<string>& ans, string ret, vector<vector<bool>>& h, vector<vector<char>>& board) {
        h[x][y] = true;
        //cout<<x<<' '<<y<<endl;
        if(now->isEnd){
            ans.push_back(ret);
            now->isEnd = false;
            now->count --;
        }
        for(int i = 0; i < 4; i ++) {
            int dx = (i%2) * ((i/2)*2-1);
            int dy = !(i%2) * ((i/2)*2-1);
            int nx = x+dx;
            int ny = y+dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !h[nx][ny]){
                char nc = board[nx][ny];
                if(now->next[nc-'a'] && now->next[nc-'a']->count){
                    int bcount = now->next[nc-'a']->count;
                    dfs(nx,ny,now->next[nc-'a'],n,m,ans,ret+nc,h,board);
                    now->count-=bcount;
                    now->count+=now->next[nc-'a']->count;
                }
            }
        }

        h[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size();
        int m = n?board[0].size():0;
        vector<vector<bool>> h(n,vector<bool>(m,false));
        int len = words.size();
        Trie* trie = new Trie();
        for(int i = 0; i < len; i ++) {
            makeTrie(words[i],trie);
        }
        string ret = "";
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(trie->next[board[i][j]-'a'])
                    dfs(i,j,trie->next[board[i][j]-'a'],n,m,ans,ret+board[i][j],h,board);
        return ans;
    }
};