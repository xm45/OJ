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
long long N,M,K,T;
long long m[20];
inline void work()
{
		long long i,j,k=0,l;
		l=M;
		int ws=0;
		while(l)
		{
			k+=l;
			k-=m[ws]-1;
			ws++;
			l/=10;
			}
		ws--;
		long long temp=k;
		if(temp>K)
		{
			printf("0\n");
			return;
			}
		if(temp==K)
		{
			printf("%d\n",temp);
			return;
			}
		i=M;j=m[ws];
		while(1)
		{
			i*=10;
			j*=10;
			if(temp+i-j>=K)
				break;
			temp=temp+i-j;
			if(i==j)
			{
				printf("0\n");
				return;
				}
			}
		printf("%lld\n",j+K-temp-1);
}
int main()
{
    int i,j,k,l;
    m[0]=1;
    for(i=1;i<=20;i++)
    	m[i]=m[i-1]*10;
    while(scanf("%lld%lld",&K,&M)!=-1)
    {
			work();
			}
    return(0);
}
