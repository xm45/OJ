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
int N,M,K,T;
int p[101];
struct V{double x,y;}v[21];
inline void ss(int sl,int qd)
{
		int i,j,k,l;
		if(sl>10)
		{
			l=0;
			for(i=1;i<=N;i++)
			{
				double jl=0;
				for(j=1;j<=10;j++)
					jl+=exp(p[j]*v[i].x);
				if(int(jl*1000+0.5)!=int(v[i].y*1000+0.5))
				{
					l=1;
					break;
					}
				}
			if(l==0)
			{
				for(i=1;i<=10;i++)
					printf("%d\n",p[i]);
				exit(0);
				}
			return;
			}
		for(i=qd;i<=10;i++)
		{
			p[sl]=i;
			ss(sl+1,i);
			}
}
int main()
{
    int i,j,k,l;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    	scanf("%lf%lf",&v[i].x,&v[i].y);
    ss(0,1);
    return(0);
}
