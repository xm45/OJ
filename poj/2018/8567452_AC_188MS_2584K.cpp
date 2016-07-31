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
int N,F;
long long xm[100001]={0},ans[100001]={0},sum[100001]={0};
int que[100001]={0},low=0,top=0;
long long maxans=0;
inline long long js(int j,int k,int i)
{
	return((sum[i]-sum[j])*(i-k)-(sum[i]-sum[k])*(i-j));
}
int main()
{
    int i,j,k,l;
    scanf("%d%d",&N,&F);
    for(i=1;i<=N;i++)
    {
	  scanf("%I64d",&xm[i]);
	  sum[i]=sum[i-1]+xm[i];
	  if(i<F)
	  {
		ans[i]=0;
	    }
	  else
	  {
		while(low<top && (sum[i]-sum[que[top]])*(que[top]-que[top-1])<(sum[que[top]]-sum[que[top-1]])*(i-que[top]))
		  top--;
		top++;
		que[top]=i-F;
		while(low<top && js(que[low],que[low+1],i)<=0)
		  low++;
		ans[i]=(long long) (double(sum[i]-sum[que[low]])/double(i-que[low])*1000);
	    if(ans[i]>maxans)
	      maxans=ans[i];
	    //printf("%d %I64d\n",que[low],ans[i]);
		}
	  }
	printf("%I64d\n",maxans);
    return(0);
}
