#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm> 
#include<queue>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;
int T;
char s[10001];
long long a[100001];
long long b[5];
int dl=0;
long long se[101];
inline void work()
{
       int ret=0;
       scanf("%s",s);
       int i,j,k,len=strlen(s);
       dl=0;
       for(i=1;i<len;i++)
       {
         for(j=1;j<=4;j++)
           b[j]=0;
         for(j=0;j<i;j++)
           b[1]=b[1]*27+s[j]-'a'+1;
         for(j=i;j<len;j++)
           b[2]=b[2]*27+s[j]-'a'+1;
         for(j=i-1;j>=0;j--)
           b[3]=b[3]*27+s[j]-'a'+1;
         for(j=len-1;j>=i;j--)
           b[4]=b[4]*27+s[j]-'a'+1;
         for(j=1;j<=4;j++)
           for(k=1;k<=4;k++)
             if(j!=k && j%2!=k%2)
             {
               int jl=0;
               for(int l=1;l<=dl;l++)
                 if(a[l]==b[j]*se[(k%2==0?len-i:i)]+b[k])
                 {
                   jl=1;
                   break;
                   }
               if(jl==0)
               {
                 dl++;
                 a[dl]=b[j]*se[(k%2==0?len-i:i)]+b[k];
                 ret++;
                 }
               }
         }
       printf("%d\n",ret);
       }
int main()
{

    scanf("%d",&T);
    se[0]=1;
    for(int i=1;i<=100;i++)
      se[i]=se[i-1]*27;
    for(int i=1;i<=T;i++)
      work();
    return(0);
}
