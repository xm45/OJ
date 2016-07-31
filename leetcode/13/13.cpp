class Solution {
public:
    int get(char m)
    {
        switch(m)
        {
            case('I'):
                return 1;
            case('V'):
                return 5;
            case('X'):
                return 10;
            case('L'):
                return 50;
            case('C'):
                return 100;
            case('D'):
                return 500;
            case('M'):
                return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int len = s.length();
        int ans = 0;
        int now = 0, last = 0;
        for(int i = 0; i < len; i++)
        {
            now = get(s[i]);
            if(now > last)
                ans -= last;
            else
                ans += last;
            last = now;
        }
        ans += last;
        return ans;
    }
};