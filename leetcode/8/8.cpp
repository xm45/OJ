class Solution {
public:
    int myAtoi(string str) {
        int flag = 0;
        int len = str.length();
        long long t = 0;
        int start = 0;
        for(int i = 0; i < len; i++)
        {
            if(i == start && str[i] == ' ')
            {
                start++;
                continue;
            }
            if(i == start && str[i] == '-')
            {
                flag = 1;
                continue;
            }
            if(i == start && str[i] == '+')
            {
                flag = 0;
                continue;
            }
            if(str[i] <= '9' && str[i] >= '0')
            {
                t *= 10;
                t += str[i]-'0';
            }
            else
                break;
            if(flag && t > (0x7fffffffL+1))
                return (-0x7fffffff-1);
            if(!flag && t > 0x7fffffffL)
                return 0x7fffffff;
        }
        if(flag)
            return -t;
        else
            return t;
    }
};