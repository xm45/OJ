#include <queue>  
#include <iostream>  
#include <stdio.h>  
#define Max 30005   
using namespace std;   
struct node    
{   
    int val;   
    node(int x){val = 0;}   
    node(){;}   
};   
int val[Max],p[Max];   
bool operator<(node a,node b)   
{   
    return a.val>b.val;   
}
int N,M;
int main()   
{   
    priority_queue<node>qmin;
    priority_queue<int>qmax;
    int i,j,tem;   
    node a;
    while (scanf("%d%d",&M,&N)!=EOF)   
    {   
        int i;   
    for(i=1;i<=M;i++)   
        scanf("%d",&val[i]);   
    for(i=1;i<=N;i++)   
            scanf("%d",&p[i]);   
        for (i=1,j=1;i<=N;i++)   
        {   
            if(!qmin.empty()&&qmax.size()<=i-1)   
            {   
                a = qmin.top();   
                qmin.pop();   
                qmax.push(a.val); 
            }   
            for (;j<=p[i];j++)   
            {   
                if (qmax.size()<=i-1)   
                    qmax.push(val[j]);   
                else  
                {   
                    if(val[j]>=qmax.top())   
                    {   
                        a.val = val[j];   
                        qmin.push(a);
                    }   
                    else  
                    {   
                        tem = qmax.top();
                        a.val = tem;
                        qmax.pop();
                        qmax.push(val[j]);
                        qmin.push(a);   
                    }   
                }   
            }
            printf("%d\n",qmax.top());
        }
        while(!qmin.empty())   
            qmin.pop();   
        while(!qmax.empty())   
            qmax.pop();   
    }   
    return 0;   
}
