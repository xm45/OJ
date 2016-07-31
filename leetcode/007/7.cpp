class Solution {
public:
    int reverse(int x) {
        stringstream ss;
        ss<<x;
        string s;
        ss>>s;
        //cout<<s<<endl;
        long long t = 0;
        int len = s.length();
        for(int i = len-1; i >= 0 ; i--)
        {
            if(s[i] == '-')
            {
              t = -t;
              continue;
            }
            t *= 10;
            t += s[i]-'0';
        }
        //cout<<t<<endl;
        if(t>0x7fffffffL||t<-(0x7fffffffL+1))
            return 0;
        else
            return t;
    }
};