#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int N,M,T;
int a[10001][2];
int dl[20001],dt;
int lsh[20001],lst;
inline bool cmp(int a,int b){return(a<b);}
inline void find(int &a)
{
       int i=1,j=lst,k,l;
       while(i<=j)
       {
         k=(i+j)/2;
         if(lsh[k]==a)
         {
           a=k;
           return;
           }
         if(lsh[k]>a)
           j=k;
         else
           i=k+1;
         }
       }
inline void ls()
{
       int i,j,k,l;
       lst=0;
       sort(dl+1,dl+dt+1,cmp);
       for(i=1;i<=dt;i++)
         if(i==1 || dl[i]!=dl[i-1])
           lsh[++lst]=dl[i];
       for(i=1;i<=N;i++)
       {
         find(a[i][0]);
         find(a[i][1]);
         }
       }
struct V
{
       int l,r;
       int ys,ef;
       }t[100001];
inline void make(int sl,int l,int r)
{
       int i,j,k;
       k=(l+r)/2;
       t[sl].l=l;
       t[sl].r=r;
       t[sl].ys=0;
       t[sl].ef=0;
       if(l!=r)
       {
         make(sl*2,l,k);
         make(sl*2+1,k+1,r);
         }
       }
inline void add(int sl,int l,int r,int ys)
{
       int i,j,k;
       if(t[sl].l==l && t[sl].r==r)
       {
         t[sl].ef=0;
         t[sl].ys=ys;
         return;
         }
       if(t[sl].ef==0)
       {
         t[sl].ef=1;
         if(t[sl].l!=t[sl].r)
         {
           t[sl*2].ys=t[sl].ys;
           t[sl*2+1].ys=t[sl].ys;
           t[sl*2].ef=t[sl*2+1].ef=0;
           }
         }
       k=(t[sl].l+t[sl].r)/2;
       if(r<=k)
         add(sl*2,l,r,ys);
       else
         if(l>=k+1)
           add(sl*2+1,l,r,ys);
         else
         {
           add(sl*2,l,k,ys);
           add(sl*2+1,k+1,r,ys);
           }
       }
int h[10001];
int ans=0;
inline void finds(int sl)
{
       int k=(t[sl].l+t[sl].r)/2;
       if(t[sl].ef==0)
         h[t[sl].ys]=1;
       if(t[sl].ef!=0 && t[sl].l!=t[sl].r)
       {
         finds(sl*2);
         finds(sl*2+1);
         }
       }
inline int get(int sl,int q)
{
       int i,j,k=t[sl].l+t[sl].r,l;
       k>>=1;
       if(t[sl].ef==0)
         return(t[sl].ys);
       if(q==t[sl].l && q==t[sl].r)
         return(t[sl].ys);
       if(q<=k)
         return(get(sl*2,q));
       else
         return(get(sl*2+1,q));
       }
inline void work()
{
       int i,j,k,l;
       dt=0;
       memset(h,0,sizeof(h));
       scanf("%d",&N);
       for(i=1;i<=N;i++)
       {
         scanf("%d%d",&a[i][0],&a[i][1]);
         dl[++dt]=a[i][0];
         dl[++dt]=a[i][1];
         }
       ls();
       make(1,1,lst);
       for(i=1;i<=N;i++)
         add(1,a[i][0],a[i][1],i);
       finds(1);
       ans=0;
       for(i=1;i<=N;i++)
         if(h[i]!=0)
           ans++;
       /*for(i=1;i<=lst;i++)
         printf("%d ",get(1,i));/**/
       printf("%d\n",ans);
       }
int main()
{
    int i,j,k,l;

    scanf("%d",&T);
    for(i=1;i<=T;i++)
      work();
    return(0);
}
