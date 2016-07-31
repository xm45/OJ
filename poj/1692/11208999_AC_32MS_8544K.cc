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
int N,M,K,T,t;
inline int rd(int a)
{
		long long b=((long long)rand()+1)*((long long)rand()+1)*((long long)rand()+1)%100000007*(rand()+1)%a+1; 
		return(b);
}
int na[10001],nb[10001];
int a[1001],b[1001];
int la[1001],lb[1001];
int f[1001][1001];
int u[1001][1001],v[1001][1001];
int ans=0;
int main()
{
    int i,j,k,l;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
      scanf("%d",&a[i]);
    for(i=1;i<=M;i++)
    	scanf("%d",&b[i]);
    memset(u,0,sizeof(u));  
    memset(v,0,sizeof(v));  
		for(i=1;i<=N;i++)	
			for(j=1;j<=M;j++)
			{
				if(a[i-1]==b[j])
					u[i][j]=i-1;
				else
				  u[i][j]=u[i-1][j];
				
				if(a[i]==b[j-1])
				  v[i][j]=j-1;
				else
				  v[i][j]=v[i][j-1];
				}
		
    for(i=1;i<=N;i++)
      for(j=1;j<=M;j++)
      {
				f[i][j]=max(f[i-1][j],f[i][j-1]);
        if(a[i]!=b[j] && u[i][j]!=0 && v[i][j]!=0)
					f[i][j]=max(f[i][j],f[u[i][j]-1][v[i][j]-1]+2);
    		ans=max(ans,f[i][j]);
    		//printf("%d %d %d\n",i,j,f[i][j]); 
				}
		printf("%d\n",f[N][M]);
		}
    return(0);
}
