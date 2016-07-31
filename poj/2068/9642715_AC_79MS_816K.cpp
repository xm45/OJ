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
int take[25];
int w[25][10001];//1 win 0 lose 
inline int ss(int sl,int q)
{
	int i,j,k,l;
	if(q==1)
	  l++;
	if(w[sl][q]!=-1)
	  return(w[sl][q]);
	if(q==0)
	  return(w[sl][q]=1);
	for(i=1;i<=take[sl] && i<q;i++)
	  if(ss(sl%(N*2)+1,q-i)==0)
	    return(w[sl][q]=1);
	return(w[sl][q]=0);
}
int main()
{
    int i,j,k,l;
    while(1)
    {
      scanf("%d",&N);
      if(N==0)
        return(0);
      scanf("%d",&M);
      for(i=1;i<=N*2;i++)
        for(j=0;j<=M;j++)
          w[i][j]=-1;
      for(i=1;i<=2*N;i++)
        scanf("%d",&take[i]);
      ss(1,M);
      printf("%d\n",w[1][M]==1);
      /*for(i=1;i<=N*2;i++)
        for(j=0;j<=M;j++)
          printf("%d %d : %d\n",i,j,w[i][j]);/**/
	  }
    return(0);
}
