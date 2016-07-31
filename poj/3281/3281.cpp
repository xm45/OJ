#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#define debug
#define MAXV 501
streambuf *cinbackup;
streambuf *coutbackup;
int N,F,D;
int Nb,Fb,Db;
int rec[MAXV][MAXV];
int dis[MAXV];
int v;
int maxflow = 0;
void add(int x,int y,int c)
{
	rec[x][y] += c;
	rec[y][x] += 0;
}
void pr()
{
	int i=0;
	for(i=0;i<v;i++)
		printf("%d %d\n",i,dis[i]);
}
int bfs()
{
	int i,j,k,l;
	memset(dis,-1,sizeof(dis));
	vector<int> st;
	int a=0;
	st.push_back(v-1);
	dis[v-1]=0;
	while(a<st.size())
	{
		int now = st[a];
		for(i=0;i<v;i++)
			if(rec[i][now]!=0 && (dis[i]==-1 || dis[now]+1<dis[i]))
			{
				dis[i] = dis[now]+1;
				st.push_back(i);
			}
		if(now == 0)
			return 1;
		a++;
	}
	return 0;
}
void dfs(int sl)
{
	//printf("%d ",sl);
	if(sl == v-1)
		return;
	int i,j,k,l;
	for(i=0;i<v;i++)
	{
		if(dis[sl] == dis[i]+1 && rec[sl][i]!=0)
		{
			dfs(i);
			rec[sl][i] -= 1;
			rec[i][sl] += 1;
			return;
		}
	}
}
bool sol()
{
	while(bfs())
	{
		//pr();
		maxflow++;
		dfs(0);
		//printf("\n");
	}
	//pr();
}
int main()
{
	#ifdef debug
	ifstream fin("input.txt");
	cinbackup= cin.rdbuf(fin.rdbuf());
	#endif
	int i,j,k,l;
	cin>>N>>F>>D;
	Nb = 0;
	Fb = N*2;
	Db = N*2+F;
	v=N*2+F+D+2;
	for(i=1;i<=N;i++)
		add(Nb+i*2-1,Nb+i*2,1);
	for(i=1;i<=N;i++)
	{
		int f,d;
		cin>>f>>d;
		for(j=0;j<f;j++)
		{
			cin>>k;
			add(Fb+k,Nb+i*2-1,1);
		}
		for(j=0;j<d;j++)
		{
			cin>>k;
			add(Nb+i*2,Db+k,1);
		}
	}
	for(i=1;i<=F;i++)
		add(0,Fb+i,1);
	for(i=1;i<=D;i++)
		add(Db+i,v-1,1);
	//for(i=0;i<elist.size();i++)
	//	printf("%d (%d %d) (%d %d) %d\n",i,elist[i].x,elist[i].y,elist[i].c,elist[i].f,elist[i].s);
	sol();
	cout<<maxflow<<endl;
	#ifdef debug
	cin.rdbuf(cinbackup);
	system("pause");
	#endif
	return 0;
}