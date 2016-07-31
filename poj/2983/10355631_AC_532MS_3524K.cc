#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm> 
#include<queue>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;
int N,M;
int fr[200001],to[200001],next[200001],len[200001],Etop=0;
int be[1001];
int dis[1001];
char c=0;
inline void add(int x,int y,int l)
{
       Etop++;
       fr[Etop]=x;
       to[Etop]=y;
       len[Etop]=l;
       next[Etop]=be[x];
       be[x]=Etop;
       }
int a,b,l;
int main()
{
    int i,j,k;

    while(scanf("%d%d",&N,&M)!=-1)
    {
      for(i=1;i<=N;i++)
        be[i]=dis[i]=0;
      Etop=0;
      for(i=1;i<=M;i++)
      {
        scanf("%*c%c",&c);
        if(c=='V')
        {
          scanf("%d%d",&a,&b);
          add(a,b,1);
          }
        else
        {
          scanf("%d%d%d",&a,&b,&l);
          add(a,b,l);
          add(b,a,-l);
          }
        }
      int fl=0;
      for(k=1;k<=N;k++)
      {
        fl=0;
        for(i=1;i<=Etop;i++)
          if(dis[to[i]]>dis[fr[i]]-len[i])
          {
            dis[to[i]]=dis[fr[i]]-len[i];
            fl=1;
            }
        if(fl==0)
          break;
        }
      if(fl==0)
        printf("Reliable\n");
      else
        printf("Unreliable\n");
      }
    
    return(0);
}
