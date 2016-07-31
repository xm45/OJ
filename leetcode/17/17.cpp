class Solution {
public:
    void dfs(int sl, string& str, string map[], vector<string>& ans, string now)
    {
        if(sl == str.length())
        {
            ans.push_back(now);
            return;
        }
        for(int i = 0; i < map[str[sl]].size(); i++)
            dfs(sl+1, str, map, ans, now+map[str[sl]][i]);
    }
    vector<string> letterCombinations(string digits) {
        string map[256];
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        map['0']="";
        map['1']="";
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="wxyz";
        map['*']="";
        map['#']="hX";
        dfs(0,digits,map,ans,"");
        return ans;
    }
};