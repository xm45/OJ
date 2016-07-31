class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int f[2][10001]={0};
        int now = 1,last = 0;
        int i,j,k,l;
        for(i=0;i<=m;i++)
            f[now][i]=i;
        for(i=1;i<=n;i++)
        {
            now^=1;
            last^=1;
            f[now][0]=i;
            for(j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    f[now][j] = f[last][j-1];
                else
                    f[now][j] = 0xfffffff;
                f[now][j]=min(f[now][j],f[last][j]+1);
                f[now][j]=min(f[now][j],f[now][j-1]+1);
                f[now][j]=min(f[now][j],f[last][j-1]+1);
            }
        }
        return f[now][m];
    }
};