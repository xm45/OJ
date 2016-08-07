
class Solution {
public:
    int calculate(string s) {
        stack<int> val;
        stack<char> op;
        int len = s.length();
        int now = 0;
        int isnum = 0;
        for(int i = 0; i < len; i ++) {
            char c = s[i];
            if(c>='0' && c<='9'){
                now = now*10 + c-'0';
                if(!isnum)
                    isnum = 1;
            }
            else if(c == '(' || c == ')' || c == '+' || c == '-'){
                if(isnum){
                    val.push(now);
                    now = 0;
                    isnum = 0;
                }
                if(op.empty())
                    op.push(c);
                else{
                    if(c == '(')
                        op.push(c);
                    else{
                        while(!op.empty() && op.top()!='('){
                            int y = val.top();
                            val.pop();
                            int x = val.top();
                            val.pop();
                            int z = 0;
                            if(op.top() =='+')
                                z = x + y;
                            else
                                z = x - y;
                            op.pop();
                            val.push(z);
                        }
                        if(c == ')')
                            op.pop();
                        else
                            op.push(c);
                    }

                }
            }
        }
        if(isnum){
            val.push(now);
            now = 0;
            isnum = 0;
        }
        while(!op.empty() && op.top()!='('){
            int y = val.top();
            val.pop();
            int x = val.top();
            val.pop();
            int z = 0;
            if(op.top() =='+')
                z = x + y;
            else
                z = x - y;
            op.pop();
            val.push(z);
        }
        return val.top();
    }
};