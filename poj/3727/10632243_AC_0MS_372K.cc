#include<stdio.h>
#include<stdlib.h>
#include<cmath>
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
const double eps=0.000001;
int N,M,K,T;
char str[10000001];
inline double f(double x)
{
		int i;
		double ans=0;
		for(i=0;str[i]!='=';i++)
		{
	   	bool p=true;
  	 	if(str[i]=='-')
			 {
    		p=false;
    		i++;
   			}
   		if(p&&str[i]=='+')
			 	i++;
   		int temp;
   		if(str[i]!='x')
			{
   			temp=0;
    		for(;str[i]!=' '&&str[i]!='x';i++)
				{
     			temp=temp*10+str[i]-'0';
    			}
   			}
   		else 
	 			temp=1;
   		if(!p)
			 	temp=-temp;
   		int t1=0;
   		if(str[i]=='x')
			{
    		if(str[i+1]=='^')
				{
     			bool pp=true;
     			if(str[i+2]=='-')
					{
      			pp=false;
      			i=i+3;
     				}
    			else 
		 				i=i+2;
     			for(;str[i]!=' ';i++)
					 	t1=t1*10+str[i]-'0';
     			if(!pp)
						t1=-t1;
    			}
    		else 
					t1=1;
   			}
   	ans=ans+double(temp)*pow(x,t1);
   	while(str[i]!=' ')
	 		i++;
		}
		return(ans);
}
inline double df(double x)
{
		int i;
		double ans=0;
		for(i=0;str[i]!='=';i++)
		{
	   	bool p=true;
  	 	if(str[i]=='-')
			 {
    		p=false;
    		i++;
   			}
   		if(p&&str[i]=='+')
			 	i++;
   		int temp;
   		if(str[i]!='x')
			{
   			temp=0;
    		for(;str[i]!=' '&&str[i]!='x';i++)
				{
     			temp=temp*10+str[i]-'0';
    			}
   			}
   		else 
	 			temp=1;
   		if(!p)
			 	temp=-temp;
   		int t1=0;
   		if(str[i]=='x')
			{
    		if(str[i+1]=='^')
				{
     			bool pp=true;
     			if(str[i+2]=='-')
					{
      			pp=false;
      			i=i+3;
     				}
    			else 
		 				i=i+2;
     			for(;str[i]!=' ';i++)
					 	t1=t1*10+str[i]-'0';
     			if(!pp)
						t1=-t1;
    			}
    		else 
					t1=1;
   			}
	  if(t1)
   	 	ans=ans+double(temp)*double(t1)*pow(x,t1-1);
		while(str[i]!=' ')
			i++;
		}
		return(ans);
}
double x[1005];
void solve()
{
		int n;
		for(n=1;n<=1000;n++)
		{
   		x[n]=x[n-1]-f(x[n-1])/df(x[n-1]);
   		if(abs(f(x[n-1]))<eps||abs(x[n]-x[n-1])<eps)
			{
    		printf("%d\n",n-1);
    		return;
   			}
			}
		printf("Bad x0 or bad equation!\n");
}
int main()
{
		int i,j,k,l;
		char s1[3];
		while(gets(str))
		{
   		if(strlen(str)==0)
	 			continue;
	 		scanf("%lf",&x[0]);
   		gets(s1);
   		solve();
			}
		return(0);
	}
