class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int len = s.length();
        int step = numRows*2-2;
        string ans = "";
        for(int i = 0; i < numRows; i++)
            for(int j = i; j < len; j += step)
            {
                ans += s[j];
                if(i != 0 && i != numRows-1)
                    if(j-i+step - i < len)
                    {
                        //cout<<j<<" "<<i<<" "<<j-i+step-i<<s[j-i+step-i]<<endl;
                        ans += s[j-i+step - i];
                    }
            }
        //cout << ans << endl;
        return ans;
    }
};