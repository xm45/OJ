#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10005;
typedef struct LNode{
int id;
int dist;
LNode*next;
}LNode,*LinkList;
LNode Tree[MAXN],mem[2*MAXN];
int nIndex;
int n,k;
int s[MAXN],sRoot,smin,sId;
int w[MAXN],num,last;
int m[MAXN];
bool cut[MAXN];
int cnt;
void Insert(LinkList head,LNode*p)
{
LinkList t=head->next;
head->next=p;
p->next=t;
}
int dfs(int root,int pt,int d)
{
int dsum=0;
LinkList lp=Tree[root].next;
for(;lp;lp=lp->next)
{
if(lp->id!=pt&&cut[lp->id]==false)
{
if(d+lp->dist<=k)
{
w[num++]=d+lp->dist;
dfs(lp->id,root,d+lp->dist);
if(0==d)
{
sort(w+last,w+num);
int l=last,r=num-1;
while(l<r)
{
w[l]+w[r]<=k?dsum+=r-l++:r--;
}
last=num;
}
}
}
}
return dsum;
}

int count(int root,int pt)
{
num=0;
last=0;
int n=dfs(root,pt,0);
sort(w,w+num);
int sum=num;
int l=0,r=num-1;
while(l<r){
w[l]+w[r]<=k?sum+=r-l++:r--;
}
return sum-n;
}

void getSize(int root,int pt)
{
LinkList lp=Tree[root].next;
int b=1;
for(;lp;lp=lp->next)
{
if(lp->id!=pt&&cut[lp->id]==false)
{
getSize(lp->id,root);
b+=s[lp->id];
}
}
s[root]=b;
}

void getRoot(int root,int pt)
{
LinkList lp=Tree[root].next;
int b=0;
for(;lp;lp=lp->next)
{
if(lp->id!=pt&&cut[lp->id]==false)
{
getRoot(lp->id,root);
if(s[lp->id]>b)
b=s[lp->id];
}
}
if(s[sRoot]-s[root]>b)
b=s[sRoot]-s[root];
if(b<smin)
{
smin=b;
sId=root;
}
}
int GB(int root,int pt)
{
smin=0xfffffff;
sRoot=root;
memset(s,0,sizeof(s));
getSize(root,pt);
getRoot(root,pt);
return sId;
}
void dp(int root,int pt)
{
int oldRoot=root;
root=GB(root,pt);
LinkList lp=Tree[root].next;
int sum=0;
if(pt!=-1&&oldRoot!=root)
cut[pt]=true;
for(;lp;lp=lp->next)
{
if(lp->id!=pt&&cut[lp->id]==false)
{
dp(lp->id,root);
sum+=m[lp->id];
}
}
if(pt!=-1)cut[pt]=true;sum+=count(root,-1);
if(pt!=-1)cut[pt]=false;
if(pt!=0&&oldRoot!=root)cut[pt]=false;
m[oldRoot]=sum;
}
int main()
{
int i,u,v,d;
while(EOF!=scanf("%d%d",&n,&k),!(n==0&&k==0))
{
memset(Tree,NULL,sizeof(Tree));
LNode*pNod=NULL;
nIndex=0;
for(i=0;i<n-1;i++)
{
scanf("%d%d%d",&u,&v,&d);
pNod=&mem[nIndex++];
pNod->id=u;
pNod->dist=d;
pNod->next=NULL;
Insert(&Tree[v],pNod);
pNod=&mem[nIndex++];
pNod->id=v;
pNod->dist=d;
pNod->next=NULL;
Insert(&Tree[u],pNod);
}
memset(cut,false,sizeof(cut));
dp(1,-1);
cnt=m[1];
printf("%d\n",cnt);
}
return 0;
}
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
