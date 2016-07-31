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
int N;
int sg[2001];
inline void make()
{
	int i,j,k,l;
	sg[0]=0;
	sg[1]=1;
	sg[2]=1;
	for(i=3;i<=2000;i++)
	{
	  int jl[2001]={0};
	  for(j=1;j<=i;j++)
	  {
		l=0;
		if(j-3>=0)
		  l^=sg[j-3];
		if(i-j-2>=0)
		  l^=sg[i-j-2];
		jl[l]=1;
	    }
	  for(j=0;j<=2000;j++)
	    if(jl[j]==0)
	    {
		  sg[i]=j;
	      break;
		  }
	  }
}
int main()
{
    int i,j,k,l;
    make();
	while(scanf("%d",&N)!=-1)
    {
	  if(sg[N])
	    printf("1\n");
	  else
	    printf("2\n");
	  }
    return(0);
}
