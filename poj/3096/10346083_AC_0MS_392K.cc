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
char s[10001];
inline void work()
{
       int i,j,k,l=strlen(s);
       for(i=1;i<l;i++)
       {
         int jl[26][26]={0};
         k=0;
         for(j=0;j+i<l;j++)
           if(jl[s[j]-'A'][s[j+i]-'A']==1)
           {
             printf("%s is NOT surprising.\n",s);
             return;
             }
           else
             jl[s[j]-'A'][s[j+i]-'A']=1;
         }
       printf("%s is surprising.\n",s);
       }
int main()
{

    while(1)
    {
      scanf("%s",s);
      if(s[0]=='*')
        break;
      work();
      }
    return(0);
}
