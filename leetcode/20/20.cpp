class Solution {
public:
    int convert(char c)
    {
        switch(c)
        {
            case('('):return 1;
            case('['):return 2;
            case('{'):return 3;
            case('}'):return -3;
            case(']'):return -2;
            case(')'):return -1;
            default: return 0;
        }
    }
    bool isValid(string s) {
        stack<int> stack;
        int size = s.length();
        for(int i = 0; i < size; i++)
        {
            int j = convert(s[i]);
            if(j > 0)
                stack.push(j);
            else
            {
                if(stack.size() == 0)
                    return false;
                int k = stack.top();
                if(j+k !=0)
                    return false;
                stack.pop();
            }
        }
        return stack.size() == 0;
    }
};