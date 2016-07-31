class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        map<char,int> m;
        int ans = 0;
        int last = -1;
        for(int i = 0; i < len; i++)
        {
            map<char,int>::iterator iter = m.find(s[i]);
            if(iter != m.end())
                last = max(last, iter->second);
            ans = max(ans, i-last);
            m[s[i]] = i;
        }
        return ans;
    }
};