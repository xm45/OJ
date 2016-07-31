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
using namespace std ;
int N;
int K;
long long xm[500001]={0},ans[500001]={0},sum[500001]={0};
int que[500001]={0},top=0,low=0; 
inline long long js(int i)
{
	return(ans[i]-sum[i]+i*xm[i+1]);
}
inline long long ask(int j,int k)
{
	return(js(j)-js(k));
}
inline long long x(int j,int k)
{
	return(xm[j+1]-xm[k+1]);
}
inline long long tw(int i,int j)
{
	return(ans[j]+sum[i]-sum[j]-(i-j)*xm[j+1]);
}
void work()
{
	int i,j,k,l;
	memset(xm,0,sizeof(xm));
	memset(ans,0,sizeof(ans));
	memset(sum,0,sizeof(sum));
	memset(que,0,sizeof(que));
	low=1;
	top=1;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)
	{
	  scanf("%I64d",&xm[i]);
	  sum[i]=sum[i-1]+xm[i];
	  if(i<K)
	  {
		ans[i]=0X19930309*19930309;
	    }
	  else
	  {
		while(low<top && 
		  ask(que[top-1],que[top])*x(que[top],i-K)>=
		  ask(que[top],i-K)*x(que[top-1],que[top]))
	      top--;
	    top++;
	    que[top]=i-K;
		while(low<top && tw(i,que[low])>=tw(i,que[low+1]))
		//while(low<top && que[low+1]<=i-K && ask(que[low],que[low+1])>=x(que[low],que[low+1])*i)
		  low++;
		ans[i]=tw(i,que[low]);
	    
	    }
	  /*printf("%d %I64d\n",que[low],ans[i]);
	  //for(j=low;j<=top;j++)
	  //  printf(" %d",que[j]);
	  //printf("\n");/**/
	  }
	printf("%I64d\n",ans[N]);
}
int T;
int main()
{
    int i,j,k,l;
    scanf("%d",&T);
    while(T)
    {
	  T--;
	  work();
	  }
    return(0);
}
