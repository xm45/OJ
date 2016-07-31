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
using namespace std;
int N,M,K,T;
int w[50001];
int dis[50001];
struct V
{
	int fa;
	int maxw,minw;
	int ansup,ansdn;
}v[50001][20];
int next[100001],to[100001],Etop;
int be[50001];
inline void add(int x,int y)
{
		Etop++;
		to[Etop]=y;
		next[Etop]=be[x];
		be[x]=Etop;
}
inline void dfs(int sl,int fa)
{
		int i,j,k,l;
		for(i=be[sl];i!=0;i=next[i])
			if(to[i]!=fa)
			{
				j=to[i];
				v[j][0].fa=sl;
				v[j][0].maxw=max(w[sl],w[j]);
				v[j][0].minw=min(w[sl],w[j]);
				v[j][0].ansup=w[sl]-w[j];
				v[j][0].ansdn=w[j]-w[sl];
				dis[j]=dis[sl]+1;
				dfs(j,sl);
				}
}
inline int get(int x,int y)
{
		int i,j,k,l,flag=0;
		V a={0},b={0};
		a.minw=b.minw=0xfffffff;
		if(dis[x]>dis[y])
		{
			swap(x,y,int);
			flag=1;
			}
		for(j=0;v[y][j].fa!=0;j++);
		j--;
		while(dis[y]>dis[x])
		{
			if(dis[v[y][j].fa]>=dis[x] && v[y][j].fa!=0)
			{
				if(b.minw==0xfffffff)
					b=v[y][j];
				else
				{
					b.fa=0;
					b.ansup=max(v[y][j].maxw-b.minw,max(b.ansup,v[y][j].ansup));
					b.ansdn=max(b.maxw-v[y][j].minw,max(b.ansdn,v[y][j].ansdn));
					b.maxw=max(b.maxw,v[y][j].maxw);
					b.minw=min(b.minw,v[y][j].minw);
					}
				y=v[y][j].fa;
				}
			else
				j--;
			}
		if(x==y)
		{
			if(flag==0)
				return(max(b.ansdn,0));
			else
				return(max(b.ansup,0));
			}
		for(j=0;v[x][j].fa!=v[y][j].fa;j++);
		
		while(x!=y)
		{
			if(v[x][j].fa!=v[y][j].fa || j==0)
			{
				if(a.minw==0xfffffff)
					a=v[x][j];
				else
				{
					a.fa=0;
					a.ansup=max(v[x][j].maxw-a.minw,max(a.ansup,v[x][j].ansup));
					a.ansdn=max(a.maxw-v[x][j].minw,max(a.ansdn,v[x][j].ansdn));
					a.maxw=max(a.maxw,v[x][j].maxw);
					a.minw=min(a.minw,v[x][j].minw);
					}
				if(b.minw==0xfffffff)
					b=v[y][j];
				else
				{
					b.fa=0;
					b.ansup=max(v[y][j].maxw-b.minw,max(b.ansup,v[y][j].ansup));
					b.ansdn=max(b.maxw-v[y][j].minw,max(b.ansdn,v[y][j].ansdn));
					b.maxw=max(b.maxw,v[y][j].maxw);
					b.minw=min(b.minw,v[y][j].minw);
					}
				x=v[x][j].fa;
				y=v[y][j].fa;
				}
			else
				j--;
			}
		if(flag)
			swap(a,b,V);
		int ans=0;
		ans=max(a.ansup,b.ansdn);
		ans=max(b.maxw-a.minw,ans);
		return(ans);
}
int main()
{
    int i,j,k,l;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    	scanf("%d",&w[i]);
    for(i=1;i<N;i++)
    {
			scanf("%d%d",&j,&k);
			add(j,k);
			}
    dfs(1,0);
    for(j=1;j<=20;j++)
    	for(i=1;i<=N;i++)
    		if(v[i][j-1].fa!=0 && v[v[i][j-1].fa][j-1].fa!=0)
    		{
					k=v[v[i][j-1].fa][j-1].fa;
					l=v[i][j-1].fa;
					v[i][j].fa=k;
					v[i][j].maxw=max(v[i][j-1].maxw,v[l][j-1].maxw);
					v[i][j].minw=min(v[i][j-1].minw,v[l][j-1].minw);
					v[i][j].ansup=max(v[l][j-1].maxw-v[i][j-1].minw,max(v[i][j-1].ansup,v[l][j-1].ansup));
					v[i][j].ansdn=max(v[i][j-1].maxw-v[l][j-1].minw,max(v[i][j-1].ansdn,v[l][j-1].ansdn));
					}
		scanf("%d",&K);
    for(i=1;i<=K;i++)
    {
			if(i==3)
				i=3;
			scanf("%d%d",&j,&k);
			printf("%d\n",get(j,k));
			}
    return(0);
}
