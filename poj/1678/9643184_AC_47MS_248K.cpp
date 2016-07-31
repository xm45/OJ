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
using namespace std;
int t;
int N,a,b;
inline bool cmp(int a,int b){return(a<b);}
inline void work()
{
	int i,j,k,l;
	scanf("%d%d%d",&N,&a,&b);
	int jl[11111]={0};
	int f[11111]={0};
	int ans=-0xfffffff;
	for(i=1;i<=N;i++)
	  scanf("%d",&jl[i]);
	sort(jl+1,jl+N+1,cmp);
	for(i=N;i>=1;i--)
	{
	  l=0;
	  f[i]=-0xfffffff;
	  for(j=i+1;j<=N;j++)
	  {
		if(jl[j]-jl[i]>=a && jl[j]-jl[i]<=b)
		{
		  l=1;
		  f[i]=max(f[i],f[j]);
		  }
		if(jl[j]-jl[i]>b)
		  break;
	    }
	  if(l==0)
	    f[i]=jl[i];
	  else
	    f[i]=jl[i]-f[i];
	  }
	l=0;
	for(i=1;i<=N;i++)
	{
	  if(jl[i]>=a && jl[i]<=b)
	  {
	    ans=max(ans,f[i]);
	    l=1;
		}
	  if(jl[i]>b)
		break;
	  }
	if(l==0)
	  printf("0\n");
	else
	  printf("%d\n",ans);
}
int main()
{
    int i,j,k,l;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
	  work();
	return(0);
}
