class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        int base = 10;
        while(x/base>=10)
            base *= 10;
        int l = 1;
        while(l <= base)
        {
            if(x/l%10 != x/base%10)
                return false;
            l *= 10;
            base /= 10;
        }
        return true;
    }
};