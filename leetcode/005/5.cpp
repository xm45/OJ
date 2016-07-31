class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        int w = 0;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            int j;
            for(j = 0; i-j >= 0 && i+j < len; j++)
                if(s[i-j] != s[i+j])
                    break;
            j--;
            if(2*j+1 > ans)
            {
                ans = 2*j+1;
                w = i-j;
            }
            for(j = 0; i-j >= 0 && i+j+1 < len; j++)
                if(s[i-j] != s[i+j+1])
                    break;
            j--;
            if(2*j+2 > ans)
            {
                ans = 2*j+2;
                w = i-j;
            }
        }
        //cout<<ans<<" "<<w<<endl;
        return s.substr(w,ans);
    }
};