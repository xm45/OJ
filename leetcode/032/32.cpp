class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.length();
        int max_len = 0, len = 0;
        int *f = new int[l+5];
        for(int i = 0; i < l; i ++)
            f[i] = 0;
        for(int i = 1; i < l; i ++) {
            if(s[i] == ')') {
            	int b = i - f[i-1] - 1;
            	if(b >= 0 && s[b] == '(') {
            		f[i] = f[i-1] + 2;
            		if(b - 1 >= 0) {
            			f[i] += f[b - 1];
            		}
            	}
            }
            max_len = max(max_len, f[i]);
        }
        return max_len;
    }
};