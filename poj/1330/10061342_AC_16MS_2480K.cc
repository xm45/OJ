#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<deque>
#include<functional>
#include<iterator>
#include<vector>
#include<list>
#include<map>
#include<memory>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#define abs(a) ((a>0)?(a):-(a))
#define sgm(a) (a==0?(0):((a>0)?(1):(-1)))
#define sqr(a) ((a)*(a))
#define swap(a,b,lx) {lx t;t=a;a=b;b=t;}
#define oo 0xfffffff
#ifndef __int64
#define I64d lld
#endif       
using namespace std ;
int N,M;
int T;
int be[10001];
int next[20001],to[20001],etop=0;
int fa[10001];
int dis[10001];
int rmq[20001][20];
int dl[20001],dltop=0;
int ff[10001];
int rmf[20001];
inline void qk()
{
       etop=0;
       memset(be,0,sizeof(be));
       //memset(next,0,sizeof(next));
       //memset(to,0,sizeof(to));
       memset(fa,0,sizeof(fa));
       //memset(dis,0,sizeof(dis));
       //memset(rmq,0,sizeof(rmq));
       //memset(dl,0,sizeof(dl));
       memset(ff,0,sizeof(ff));
       //memset(rmf,0,sizeof(rmf));
       }
inline void dfs(int sl,int fa)
{
       int i,j,k,l;
       for(i=be[sl];i!=0;i=next[i])
         if(to[i]!=fa)
         {
           dis[to[i]]=dis[sl]+1;
           dl[++dltop]=sl;
           if(ff[sl]==0)
             ff[sl]=dltop;
           dfs(to[i],sl);
           dl[++dltop]=to[i];
           if(ff[to[i]]==0)
             ff[to[i]]=dltop;
           }
       }
//dis[dl[i]]<dis[dl[j]]
inline void make_rmq()
{
       int i,j,k,l;
       for(i=1;i<=dltop;i++)
         rmq[i][0]=dl[i];
       for(j=1;(1<<j)<=dltop;j++)
         for(i=1;i<=dltop-(1<<j)+1;i++)
           if(dis[rmq[i][j-1]]<dis[rmq[i+(1<<(j-1))][j-1]])
             rmq[i][j]=rmq[i][j-1];
           else
             rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
       }
inline int find(int x,int y)
{
       int i=min(x,y),j=max(x,y);
       int l=(int)(rmf[j-i+1]);
       if(dis[rmq[i][l]]<dis[rmq[j-(1<<l)+1][l]])
         return(rmq[i][l]);
       else
         return(rmq[j-(1<<l)+1][l]);
       }
inline void make()
{
       int i,j,k,l=1;
       dltop=0;
       while(fa[l]!=0)
         l=fa[l];
       dis[l]=1;
       dfs(l,0);
       make_rmq();
       }
inline void add(int x,int y)
{
       etop++;
       next[etop]=be[x];
       to[etop]=y;
       be[x]=etop;
       }
inline void csh()
{
       int i,j,k,l;
       for(i=0;(1<<i)<=10000;i++)
         rmf[1<<i]=i;
       for(i=1;i<=10000;i++)
         if(rmf[i]==0)
           rmf[i]=rmf[i-1];
       }
inline int find2(int a,int b)
{
       int h[10001]={0};
       while(a!=0)
       {
         h[a]=1;
         a=fa[a];
         }
       while(h[b]==0)
       {
         h[b]=1;
         b=fa[b];
         }
       return(b);
       }
int main()
{

    int i,j,k,l;
    scanf("%d",&T);
    csh();
    for(l=1;l<=T;l++)
    {
      qk();
      scanf("%d",&N);
      for(i=1;i<N;i++)
      {
        scanf("%d%d",&j,&k);
        add(j,k);
        add(k,j);
        fa[k]=j;
        }
      make();
      scanf("%d%d",&j,&k);
      printf("%d\n",find2(j,k));
      }
    return(0);
}
