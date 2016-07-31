#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int N;
int M,K;
vector<int> G[1100];
int sg[1100];
int ans[1100];
bool used[1100];
int Ismany[1100][1100];

void rang(int ct,int be,int f,int cnt,int &ans,int &last)
{
	used[be] = 1;

	for(int i=G[be].size()-1;i>=0;i--)
	{
		if(Ismany[be][G[be][i]]==1)
		{
			if( G[be][i]==ct )
			{
				last = be;
				ans = cnt+1;break;
			}
			if( !used[G[be][i]] )
			{
				Ismany[be][G[be][i]]--;
				Ismany[G[be][i]][be]--;
				rang(ct,G[be][i],f,cnt+1,ans,last);
				Ismany[be][G[be][i]]++;
				Ismany[G[be][i]][be]++;
			}
		}
	}

	if(f) used[be] = 0;
}

int dfs(int x)
{
	int& cur = sg[x];
	if(cur!=-1) return cur;

	cur = 0;
	used[x] = 1;
	int cnt,ans,last;
	for(int i=G[x].size()-1;i>=0;i--)
	{
		if( !used[G[x][i]] )
		{
			if( Ismany[x][G[x][i]]>1 )
			{
				used[G[x][i]] = 1;
				continue;
			}

			ans = -1;
			cnt = 1;
			last = -1;

			Ismany[x][G[x][i]]--;
			Ismany[G[x][i]][x]--;
			rang(x,G[x][i],1,cnt,ans,last);
			Ismany[x][G[x][i]]++;
			Ismany[G[x][i]][x]++;

			if( ans!=-1 )
			{
				if(ans&1) cur^=1;
				else cur^=0;
			}
			if(ans!=-1) 
			{
				used[G[x][i]] = 1;
				used[last] = 1;
			}
			else
			{
				cur ^= (dfs(G[x][i])+1);
			}
		}
	}

	return cur;
}

int main()
{
	int s,t;
	while(scanf("%d",&N)==1)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&M,&K);
			for(int j=1;j<=M;j++) G[j].clear();
			memset(Ismany,0,sizeof(Ismany));
			for(int j=0;j<K;j++)
			{
				scanf("%d %d",&s,&t);
				Ismany[s][t]++;
				Ismany[t][s]++;
				G[s].push_back(t);
				G[t].push_back(s);
			}

			//
			memset(sg,-1,sizeof(sg));
			memset(used,0,sizeof(used));
			ans[i] = dfs(1);
			//printf("sg: %d\n",ans[i]);
		}

		int win = 0;
		for(int i=0;i<N;i++)
			win ^= ans[i];
		if(win) printf("Sally\n");
		else printf("Harry\n");
	}
	return 0;
}
