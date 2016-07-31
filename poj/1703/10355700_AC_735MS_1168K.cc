#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm> 
#include<queue>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;
int T;
int N,M;
int fa[100001];
int gx[100001];
inline int find(int x)
{
       if(x==fa[x])
         return(x);
       else
       {
         int l=find(fa[x]);
         gx[x]=gx[x]^gx[fa[x]];
         fa[x]=l;
         return(fa[x]);
         }
       }
char c;
int a,b;
int main()
{
    int i,j,k,l;

    scanf("%d",&T);
    for(l=1;l<=T;l++)
    {
      scanf("%d%d",&N,&M);
      for(i=1;i<=N;i++)
        fa[i]=i,gx[i]=0;
      for(i=1;i<=M;i++)
      {
        scanf("%*c%c",&c);
        if(c=='A')
        {
          scanf("%d%d",&a,&b);
          j=find(a);
          k=find(b);
          if(j!=k)
            printf("Not sure yet.\n");
          else
            if(gx[a]==gx[b])
              printf("In the same gang.\n");
            else
              printf("In different gangs.\n");
          }
        else
        {
          scanf("%d%d",&a,&b);
          j=find(a);
          k=find(b);
          if(j==k)
            ;
          else
          {
            fa[j]=k;
            gx[j]=gx[a]^gx[b]^1;
            }
          }
        }
      
      }
    return(0);
}
