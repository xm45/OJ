class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int size = strs.size();
        if(size == 0)
            return ans;
        for(int i = 0; ; i++)
        {
            for(int j = 0; j < size; j++)
                if(strs[j].length() < i+1 || strs[j][i] != strs[0][i])
                    return ans;
            ans += strs[0][i];
        }
    }
};