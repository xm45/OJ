class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)
            return "";
        if(n == 1)
            return "1";
        string last = countAndSay(n-1);
        int len = last.length();
        stringstream ss;
        string ans = "";
        int count = 0;
        char now = ' ';
        for(int i = 0; i < len; i ++) {
            if(now == ' '){
                now = last[i];
                count = 1;
                continue;
            }
            if(last[i] == now)
                count ++;
            else {
                ss<<count;
                ss<<now;
                now = last[i];
                count = 1;
            }
        }
        if(now != ' '){
            ss<<count;
            ss<<now;
        }
        ss>>ans;
        //cout<<n<<' '<<ans<<endl;
        return ans;
    }
};