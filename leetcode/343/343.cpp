class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int ans = 1;
        int x = n/3;
        int y = n%3;
        if(y == 1) {
            x--;
            ans += 3;
        }
        while(x--)
            ans *= 3;
        if(y == 2)
            ans *= 2;
        return ans;
    }
};