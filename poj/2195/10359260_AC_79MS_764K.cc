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
char c;
struct V{int x,y;}m[10001],h[10001];
int ht,mt;
int next[1000001],to[1000001],flow[1000001],fy[1000001],Etop=-1;
int be[10001];
inline void add(int x,int y,int f)
{
       Etop++;
       to[Etop]=y;
       next[Etop]=be[x];
       flow[Etop]=1;
       fy[Etop]=f;
       be[x]=Etop;
       
       Etop++;
       to[Etop]=x;
       next[Etop]=be[y];
       flow[Etop]=0;
       fy[Etop]=-f;
       be[y]=Etop;
       }
int before[1001];
int dis[1001];
int st[10001],top;
inline int dfs()
{
       int i,j,k,l;
       top=0;
       for(i=0;i<=ht+mt+1;i++)
         before[1001]=-1,dis[i]=0xfffffff;
       int dl[10001],h[1001]={0},now=1,dt=1;
       dl[1]=0;
       dis[0]=0;
       h[0]=1;
       for(;now<=dt;now++)
       {
         int dq=dl[now];
         for(i=be[dq];i!=-1;i=next[i])
           if(dis[dq]+fy[i]<dis[to[i]] && flow[i]==1)
           {
             dis[to[i]]=dis[dq]+fy[i];
             before[to[i]]=i;
             if(h[to[i]]==0)
             {
               h[to[i]]=1;
               dl[++dt]=to[i];
               }
             }
         h[dq]=0;
         }
       if(dis[mt+ht+1]==0xfffffff)
         return(-1);
       top=0;
       i=mt+ht+1;
       while(i!=0)
       {
         st[++top]=before[i];
         i=to[before[i]^1];
         }
       return(1);
       }
inline int get()
{
       int i,j,k,l;
       int ans=0;
       while(dfs()!=-1)
       {
         l=0xfffffff;
         for(i=1;i<=top;i++)
         {
           flow[st[i]]--;
           flow[st[i]^1]++;
           ans+=fy[st[i]];
           }
         }
       /*for(i=0;i<=Etop;i++)
         if(flow[i]==0 && i%2==0)
           printf("%d %d %d\n",to[i^1],to[i],fy[i]);/**/
       return(ans);
       }
int main()
{
    int i,j,k,l;

    while(1)
    {
      scanf("%d%d",&N,&M);
      if(N==0)
        return(0);
      mt=ht=0;
      for(i=1;i<=N;i++)
      {
        scanf("%*c");
        for(j=1;j<=M;j++)
        {
          scanf("%c",&c);
          if(c=='m')
            m[++mt]=(V){i,j};
          if(c=='H')
            h[++ht]=(V){i,j};
          }
        }
      for(i=0;i<=mt+ht+1;i++)
        be[i]=-1;
      Etop=-1;
      for(i=1;i<=mt;i++)
        for(j=1;j<=ht;j++)
        {
          add(i,mt+j,abs(m[i].x-h[j].x)+abs(m[i].y-h[j].y));
          //printf("%d %d %d\n",i,i+j,abs(m[i].x-h[j].x)+abs(m[i].y-h[j].y));
          }
      for(i=1;i<=mt;i++)
        add(0,i,0);
      for(i=1;i<=ht;i++)
        add(mt+i,mt+ht+1,0);
      printf("%d\n",get());
      }
    return(0);
}
