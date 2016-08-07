
class Solution {
public:
    int calculate(string s) {
        stack<int> val;
        stack<char> op;
        int now = 0;
        int isnum = 0;
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            int c = s[i];
            if(c >= '0' && c <= '9'){
                now = now*10 + c-'0';
                isnum = 1;
            }
            if(c == '+' || c == '-' || c== '*' || c== '/') {
                if(isnum){
                    val.push(now);
                    now = 0;
                    isnum = 0;
                }
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    int y = val.top();
                    val.pop();
                    int x = val.top();
                    val.pop();
                    int z = 0;
                    if(op.top() == '*')
                        z = x*y;
                    else
                        z = x/y;
                    op.pop();
                    val.push(z);
                }
                if(c == '+' || c == '-')
                    while(!op.empty()){
                        int y = val.top();
                        val.pop();
                        int x = val.top();
                        val.pop();
                        int z = 0;
                        if(op.top() == '*')
                            z = x*y;
                        else if(op.top() == '/')
                            z = x/y;
                        else if(op.top() == '+')
                            z = x+y;
                        else
                            z = x-y;
                        op.pop();
                        val.push(z);
                    }
                op.push(c);
            }
        }
        if(isnum){
            val.push(now);
            now = 0;
            isnum = 0;
        }
        while(!op.empty()){
            int y = val.top();
            val.pop();
            int x = val.top();
            val.pop();
            int z = 0;
            if(op.top() == '*')
                z = x*y;
            else if(op.top() == '/')
                z = x/y;
            else if(op.top() == '+')
                z = x+y;
            else
                z = x-y;
            op.pop();
            val.push(z);
        }
        return val.top();
    }
};