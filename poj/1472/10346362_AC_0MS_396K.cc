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
struct V{int n[12];};
inline V sc(V &a,int b)
{
       for(int i=0;i<=11;i++)
         a.n[i]*=b;
       }
inline V jc(V &a)
{
       for(int i=11;i>=1;i--)
         a.n[i]=a.n[i-1];
       a.n[0]=0;
       }
inline V add(V a,V b)
{
       V c={0};
       for(int i=0;i<=11;i++)
         c.n[i]=a.n[i]+b.n[i];
       return(c);
       }
char s[10001];
inline int zh()
{
       int i,l=strlen(s);
       int ret=0;
       for(i=0;i<l;i++)
         ret=ret*10+s[i]-'0';
       return(ret);
       }
inline void work(V &a)
{
       while(scanf("%s",s))
       {
         if(s[0]=='E')
           break;
         if(s[0]=='O')
         {
           int num=0;
           scanf("%s",s);
           num=zh();
           a.n[0]+=num;
           }
         if(s[0]=='L')
         {
           int num=0;
           scanf("%s",s);
           if(s[0]=='n')
             num=-1;
           else
             num=zh();
           V b={0};
           work(b);
           if(num==-1)
             jc(b);
           else
             sc(b,num);
           a=add(a,b);
           }
         }
       }
inline void pr(V a)
{
       int i,j,k,l=0;
       for(i=11;i>=0;i--)
         if(a.n[i]!=0)
         {
           if(l==1)
             printf("+");
           if(i!=0 && a.n[i]!=1)
             printf("%d*",a.n[i]);
           if(i>1)
             printf("n^%d",i);
           else
             if(i==1)
               printf("n");
           if(i==0)
             printf("%d",a.n[i]);
           l=1;
           }
       if(l==0)
         printf("0");
       printf("\n");
       }
int main()
{

    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
      V a={0};
      scanf("%*s");
      work(a);
      printf("Program #%d\n",i);
      printf("Runtime = ");
      pr(a);
      printf("\n");
      }
    return(0);
}
