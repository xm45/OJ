class Solution {
public:
    int divide(int dividend, int divisor) {
        long ans = 0;
        long n1 = long(dividend);
        long n2 = long(divisor);
        if(n2 == 0)
            return 0x7fffffff;
        if(n1 == 0)
            return 0;
        printf("%ld %ld\n",n1,n2);
        bool f1 = 0,f2 = 0;
        if(n1 < 0)
        {
            f1 = 1;
            n1 = -n1;
        }
        if(n2 < 0)
        {
            f2 = 1;
            n2 = -n2;
        }
        printf("%ld %ld\n",n1,n2);
        printf("%d %d %d\n",f1,f2,f1^f2);
        long d = n2;
        long dans = 1;
        while(d < n1)
        {
            d <<= 1;
            dans <<= 1;
        }
        while(n1 >= n2)
        {
            if(n1 < d)
            {
                d >>= 1;
                dans >>= 1;
            }
            else
            {
                ans += dans;
                n1 -= d;
            }
        }
        if(f1 ^ f2 == 1)
            ans = -ans;
        if(ans > 0x7fffffffL)
            return 0x7fffffff;
        return ans;
    }
};