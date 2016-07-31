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
int t;
int N,M,K;
int a[11111];
int sg[11111];
inline void make()
{
	int i,j,k,l;
	memset(sg,0,sizeof(sg));
	for(i=1;i<=10000;i++)
	{
	  bool pd[11111]={0};
	  for(j=1;j<=N;j++)
	    if(i-a[j]>=0)
	      pd[sg[i-a[j]]]=1;
	  for(j=0;j<=10000;j++)
	    if(pd[j]==0)
	    {
	      sg[i]=j;
	      break;
		  }
	  }
	
}
int main()
{
    int i,j,k,l;
    while(1)
    {
	  scanf("%d",&N);
	  if(N==0)
	    break;
	  for(i=1;i<=N;i++)	
		scanf("%d",&a[i]);
	  make();
	  scanf("%d",&M);
	  for(i=1;i<=M;i++)
	  {
		int ans=0;
		scanf("%d",&K);
		for(j=1;j<=K;j++)
		{
		  scanf("%d",&k);
		  ans^=sg[k];
		  }
	    if(ans)
	      printf("W");
	    else
	      printf("L");
	    }
	  printf("\n");
	}
    return(0);
}
