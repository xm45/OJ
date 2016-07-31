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
int T;
int N;
inline void work()
{
	int i,j,k,l;
	int a[1001]={0};
	int b[1001]={0};
	int ans=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+N+1);
	a[0]=0;
	for(i=1;i<=N;i++)
	  b[i]=a[N-i+1]-a[N-i]-1;
	for(i=1;i<=N;i++)
	  if(i%2==1)
	    ans=ans^b[i];
	if(ans==0)
	  printf("Bob will win\n");
	else
	  printf("Georgia will win\n");
}
int main()
{
    int i,j,k,l;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
      work();
    return(0);
}
