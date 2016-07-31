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
#define ll long long
using namespace std ;
int T;
int N;
int num[40];
int cl[101];
char c;
ll C1,C2;
inline ll work(int n)
{
	int i,j,k,l=0;
	ll jn=((ll)1<<(50));
	ll ans=0;
	scanf("%*c");
	for(i=1;i<=n;i++)
	{
	  scanf("%c",&c);
	  if(i!=n)
	    scanf("%*c");
	  if(c=='W')
	    cl[i]=1;
	  else
	    cl[i]=0;
	  }
	l=0;
	for(i=1;i<=n;i++)
	{
	  if(cl[i]!=cl[1])
	    l=1;
	  if(l==1)
	    jn/=2;
	  if(cl[i]==1)
	    ans+=jn;
	  else
	    ans-=jn;
	  }
	return(ans);
}
inline ll js()
{
	int i,j,k,l;
	ll ans=0;
	for(i=1;i<=3;i++)
	  scanf("%d",&num[i]);
	for(i=1;i<=3;i++)
	  ans+=work(num[i]);
	return(ans);
}
int main()
{
    int i,j,k,l;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
	  scanf("%*s %*d");
	  C1=js();
	  C2=js();
	  printf("Test %d: ",i);
	  if(C1>=C2)
	    printf("Yes\n");
	  else
	    printf("No\n");
	  }
    return(0);
}
