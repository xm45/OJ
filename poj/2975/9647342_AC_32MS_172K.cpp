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
int a[10001];
int main()
{
    int i,j,k,l;
    while(1)
    {
	  int ans=0;
	  scanf("%d",&N);
	  if(N==0)
	    break;
	  for(i=1;i<=N;i++)
	  {
	    scanf("%d",&a[i]);
	    ans^=a[i];
	    }
	  int jl=0;
	  if(ans!=0)
	    for(i=1;i<=N;i++)
	      if(a[i]>=(ans^a[i]))
	        jl++;
	  printf("%d\n",jl);
	  }
    return(0);
}
