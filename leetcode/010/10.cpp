class Solution {
public:
    bool isMatch(string s, string p) {
        //cout<<s<<" "<<p<<endl;
        //cout<<s.length()<<" "<<p.length()<<endl;
        if(p.length() == 0 && s.length() == 0)
            return true;
        if(p.length() == 0 && s.length() != 0)
            return false;
        bool ans = false;
        if(p.length() >= 2 && p[1] == '*')
        {
            ans |= isMatch(&s[0],&p[2]);
            if(ans == true)
                return ans;
            if((p[0] == '.' && s.length() != 0) || p[0] == s[0])
                ans |= isMatch(&s[1],&p[0]);
        }
        else if(s.length() == 0 || p.length() == 0)
            ans |= false;
        else if(p[0] == '.' || p[0] == s[0])
            ans |= isMatch(&s[1],&p[1]);
        else
            ans = false;
        //cout<< ans <<endl;
        return ans;
    }
};