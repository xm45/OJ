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
struct V
{
       int y,m,d;
       }s,e,b;
inline int rn(V a)
{
       if(a.y==1700)
         return(1);
       if(a.y<1582 && a.y%4==0)
         return(1);
       if(a.y>=1582 &&(a.y%100==0?(a.y%400==0):(a.y%4==0)))
         return(1);
       return(0);
       }
inline int day(V a)
{
       if(a.m==9)
         return(30-(a.y==1752?11:0));
       if(a.m==2)
         return(28+rn(a));
       if(a.m==1||a.m==3||a.m==5||a.m==7||a.m==8||a.m==10||a.m==12)
         return(31);
       return(30);
       }
inline bool x(V a,V b)
{
       if(a.y<b.y)
         return(1);
       if(a.y==b.y && a.m<=b.m)
         return(1);
       return(0);
       }
inline void add(V &b)
{
       b.d=(b.d+day(b))%7;
       b.m++;
       if(b.m>12)
       {
         b.m=1;
         b.y++;
         }
       }
int l,g;
inline void get(V b)
{
       if(b.d==1 || b.d==0 || b.d==6)
         g++;
       int i=(b.d+day(b))%7;
       if(i==6 || i==0 || i==1)
         l++;
       }
int main()
{

    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
      scanf("%d%d%d%d",&s.y,&s.m,&e.y,&e.m);
      b.y=1;
      b.m=1;
      b.d=6;
      g=l=0;
      for(;x(b,e);add(b))
      {
        if(x(s,b) && x(b,e))
          get(b);
        }
      printf("%d %d\n",l,g);
    }
    return(0);
}
