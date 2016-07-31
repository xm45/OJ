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
vector<int>v[1001];
bool s[1001];
int low[1001];
int d[1001];
int color[1001];
bool flag[1001];
int n;
void dfs(int x,int k) 
{
    int i,j,sum=0,w; 
    d[x]=k; 
    low[x]=k;
    color[x]=1;
    for(i=0;i<v[x].size();i++)
    {
        w=v[x][i];                      
        if(!color[w]) 
        {
           sum++;
           flag[x]++;
           dfs(w,k+1);
           if(low[x]>low[w])low[x]=low[w];
           if((x==1&&sum>1)||(x!=1&&low[w]>=d[x]))
           {
              s[x]=1;                                      
              }
           if(low[w]>d[x])flag[w]++;               
           }
        else if(x!=w) 
        {
           if(low[x]>d[w])low[x]=d[w]; 
           }                         
        } 
    } 
void dfs2(int x)
{
    int i,j;
    for(i=0;i<v[x].size();i++)
    {
        if(flag[v[x][i]]==0)
        {
           flag[v[x][i]]=1;
           dfs2(v[x][i]);                 
           }                      
        } 
    }        
int main()
{
    int i,j,k,l;

    int x,y,c=1,len,key;
    scanf("%d",&x);
    for(i=1;i<=1000;i++)
    {
        v[i].clear();
        low[i]=0;
        d[i]=0;
        color[i]=0;
        s[i]=0;               
        }    
    while(x)
    {
         n=0;
         len=0;
         if(n<x)n=x;
         while(x)
         {
               scanf("%d",&y);
               if(n<y)n=y;
               v[x].push_back(y);
               v[y].push_back(x);
               scanf("%d",&x); 
               }    
         dfs(1,1);
         printf("Network #%d\n",c++);
         for(i=1;i<=n;i++)
         {            
             if(s[i])
             {
                for(j=1;j<=n;j++)
                {
                    flag[j]=0;             
                    }     
                flag[i]=1;
                int count=0;
                for(j=0;j<v[i].size();j++)
                {
                    if(flag[v[i][j]]==0){count++;dfs2(v[i][j]);}                      
                    }
                printf("  SPF node %d leaves %d subnets\n",i,count);        
                len++;
                }             
             }   
         if(len==0)printf("  No SPF nodes\n\n");
         else printf("\n");
         scanf("%d",&x);
         for(i=1;i<=n;i++)
         {
             v[i].clear();
             low[i]=0;
             d[i]=0;
             flag[i]=0;
             color[i]=0;
             s[i]=0;             
             }      
         }    
    return 0;
    }
