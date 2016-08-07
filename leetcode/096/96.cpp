class Solution {
public:
    int numTrees(int n) {
        vector<int> catalan(n+1,0);
        catalan[0] = 1;
        catalan[1] = 1;
        for(int i = 2; i <= n; i ++)
            for(int j = 0; j < i; j ++)
                catalan[i] += catalan[j]*catalan[i-1-j];
        return catalan[n];
    }
};