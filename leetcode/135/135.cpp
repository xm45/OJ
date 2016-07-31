class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int> candy(n,0);
        for(int i = 0; i < n; i++){
            if(candy[i] == 0)
                candy[i] = 1;
            if(i != 0)
                if(ratings[i] > ratings[i-1])
                    candy[i] = max(candy[i], candy[i-1] + 1);
        }

        for(int i = n - 1; i >= 0; i--){
            if(candy[i] == 0)
                candy[i] = 1;
            if(i != n - 1)
                if(ratings[i] > ratings[i+1])
                    candy[i] = max(candy[i], candy[i+1] + 1);
        }
        for(int i = 0; i < n; i++)
            ans += candy[i];
        return ans;
    }
};