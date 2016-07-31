#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char> >& grid, int &x,int &y, int &r, int &c, int fx[4][2]){
    	grid[x][y] = '2';
    	int i = 0, j = 0;
		for(int f = 0; f < 4; f++){
    		i = x + fx[f][0];
    		j = y + fx[f][1];
    		if(i >= 0 && i < r && j >= 0 && j < c && grid[i][j] == '1'){
    			dfs(grid, i, j, r, c, fx);
    		}
    	}
    }
    int numIslands(vector<vector<char> >& grid) {
  		int fx[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        int r = grid.size();
        int c = 0;
        int ans = 0;
		if(r != 0)
			 c = grid[0].size();
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(grid[i][j] == '1'){
					dfs(grid, i, j, r, c, fx);
					ans++;
				}
			}
		}
		return ans;
    }
};
int main(){
	
}
