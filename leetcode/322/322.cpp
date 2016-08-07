class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> num(amount+1,INT_MAX);
        num[0] = 0;
        int len = coins.size();
        for(int i = 0; i <= amount; i ++)
            if(num[i] != INT_MAX)
                for(int j = 0; j < len; j++)
                    if(i + coins[j] <= amount)
                        if(num[i]+1 < num[i + coins[j]])
                            num[i + coins[j]] = num[i] + 1;
        return num[amount] == INT_MAX?-1:num[amount];
    }
};