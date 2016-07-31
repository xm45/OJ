#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int N,M,T;
struct E{int a,b;}e[10001];
int next[10001],to[10001],Etop;
int be[10001];
int belong[10001];
int flag1[10001],flag2[10001];
int fs[10001];
int st[10001],t=0;
inline void add(int x,int y)
{
       Etop++;
       to[Etop]=y;
       next[Etop]=be[x];
       be[x]=Etop;
       }
inline void dfs(int sl,int fe)
{
       int i,j,k,l;
       flag1[sl]=1;
       st[++t]=sl;
       fs[sl]=t;
       for(i=be[sl];i!=0;i=next[i])
         if(abs(i-fe)!=1 || min(i,fe)%2==0)
         {
           if(flag1[to[i]]==0)
             dfs(to[i],i);
           else
           {
             for(j=fs[to[i]];j<=t;j++)
               belong[st[j]]=to[i];
             }
           }
       t--;
       }
inline int find(int x){return(x==belong[x]?x:belong[x]=find(belong[x]));}
int jl=0;
int ds[100001];
inline void dfs2(int sl,int fa)
{
       int i,j,k,l=0;
       flag2[sl]=1;
       for(i=be[sl];i!=0;i=next[i])
         if(to[i]!=fa && flag2[to[i]]==0)
         {
           l++;
           dfs2(to[i],sl);
           }
       if((fa!=0 && l==0) ||(fa==0 && l==1))
         jl++;
       }
int main()
{
    int i,j,k,l;

    while(scanf("%d%d",&N,&M)!=-1)
    {
      jl=0;
      for(i=1;i<=N;i++)
        ds[i]=be[i]=flag1[i]=flag2[i]=0,belong[i]=i;
      Etop=0;
      t=0;
      for(i=1;i<=M;i++)
      {
        scanf("%d%d",&e[i].a,&e[i].b);
        add(e[i].a,e[i].b);
        add(e[i].b,e[i].a);
        }
      dfs(1,0);
      for(i=1;i<=N;i++)
        find(i);
      Etop=0;
      for(i=1;i<=M;i++)
        if(belong[e[i].a]!=belong[e[i].b])
        {
          ds[belong[e[i].a]]++;
          ds[belong[e[i].b]]++;
          }
      for(i=1;i<=N;i++)
        if(belong[i]==i && ds[i]==1)
          jl++;
      printf("%d\n",(jl+1)/2);
      }
    return(0);
}
