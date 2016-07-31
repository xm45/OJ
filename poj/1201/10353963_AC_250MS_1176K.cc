#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm> 
#include<queue>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;
int N;
struct V{int a,b,c;}v[100001];
int s[100001];
int a=0xfffffff,b;
int main()
{
    int i,j,k,l;

    scanf("%d",&N); 
    for(i=1;i<=N;i++)
    {
      scanf("%d %d %d",&v[i].a,&v[i].b,&v[i].c);
      v[i].b++;
      if(v[i].a<a)
        a=v[i].a;
      if(v[i].b>b)
        b=v[i].b;
      }
    int f=1;
    while(f==1)
    {
      f=0;
      for(i=1;i<=N;i++)
        if(s[v[i].a]>s[v[i].b]-v[i].c)
        {
          s[v[i].a]=s[v[i].b]-v[i].c;
          f=1;
          }
      for(i=a;i<b;i++)
        if(s[i+1]>s[i]+1)
        {
          s[i+1]=s[i]+1;
          f=1;
          }
      for(i=b-1;i>=a;i--)
        if(s[i]>s[i+1])
        {
          s[i]=s[i+1];
          f=1;
          }
      }
    printf("%d\n",s[b]-s[a]);
    return(0);
}
