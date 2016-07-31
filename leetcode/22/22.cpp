class Solution {
public:
    void generate(vector<string>& ans, int l, int r, string s)
    {
        if(l == 0 && r == 0)
        {
            ans.push_back(s);
            return;
        }
        if(l > 0)
            generate(ans,l-1,r,s+"(");
        if(r > 0 && l < r)
            generate(ans,l,r-1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,n,n,"");
        return ans;
    }
};