#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
char map[10][16];
bool vist[10][15];
int MaxSize=-1;
char MaxColor;
int MaxR,MaxC;

int BFSArea(int i,int j)
{
	class
	{
	public:
		int x,y;
	}queue[151];

	int head,tail;
	queue[head=tail=0].x=i;
	queue[tail++].y=j;
	vist[i][j]=true;

	int size=0;
	char color=map[i][j];
	while(head<tail)
	{
		int x=queue[head].x;
		int y=queue[head++].y;
		size++;

		if(x+1<10 && !vist[x+1][y] && map[x+1][y]==color)
		{
			vist[x+1][y]=true;
			queue[tail].x=x+1;
			queue[tail++].y=y;
		}
		if(x-1>=0 && !vist[x-1][y] && map[x-1][y]==color)
		{
			vist[x-1][y]=true;
			queue[tail].x=x-1;
			queue[tail++].y=y;
		}
		if(y-1>=0 && !vist[x][y-1] && map[x][y-1]==color)
		{
			vist[x][y-1]=true;
			queue[tail].x=x;
			queue[tail++].y=y-1;
		}
		if(y+1<15 && !vist[x][y+1] && map[x][y+1]==color)
		{
			vist[x][y+1]=true;
			queue[tail].x=x;
			queue[tail++].y=y+1;
		}
	}
	return size;
}
void SearchMaxArea(void)
{
	memset(vist,false,sizeof(vist));
	MaxSize=0;

	for(int j=0;j<15;j++)
		for(int i=0;i<10;i++)
		{
			int size=0;
			if(!vist[i][j] && map[i][j])
			{
				size=BFSArea(i,j);
				if(MaxSize<size)
				{
					MaxSize=size;
					MaxR=i;
					MaxC=j;
				}
			}
		}
	return;
}
void DelMaxArea(void)
{
	class
	{
	public:
		int x,y;
	}queue[151];

	int head,tail;
	queue[head=tail=0].x=MaxR;
	queue[tail++].y=MaxC;

	MaxColor=map[MaxR][MaxC];
	map[MaxR][MaxC]=0;
	while(head<tail)
	{
		int x=queue[head].x;
		int y=queue[head++].y;
		map[x][y]=0;

		if(x+1<10 && map[x+1][y]==MaxColor)
		{
			map[x+1][y]=0;
			queue[tail].x=x+1;
			queue[tail++].y=y;
		}
		if(x-1>=0 && map[x-1][y]==MaxColor)
		{
			map[x-1][y]=0;
			queue[tail].x=x-1;
			queue[tail++].y=y;
		}
		if(y-1>=0 && map[x][y-1]==MaxColor)
		{
			map[x][y-1]=0;
			queue[tail].x=x;
			queue[tail++].y=y-1;
		}
		if(y+1<15 && map[x][y+1]==MaxColor)
		{
			map[x][y+1]=0;
			queue[tail].x=x;
			queue[tail++].y=y+1;
		}
	}
	return;
}
void RefreshMap(void)
{
	bool empty[15]={false};
	int i,j;
	for(j=0;j<15;j++)
	{
		bool flag=false;
		int pi=-1;
		for(i=0;i<10;i++)
		{
			if(map[i][j])
			{
				flag=true;
				if(pi!=-1)
				{
					map[pi][j]=map[i][j];
					map[i][j]=0;
					i=pi;
					pi=-1;
				}
			}
			else
			{
				pi=i;
				while(i+1<10 && !map[i+1][j])
					i++;
			}
		}
		if(!flag)
			empty[j]=true;
	}
	int k=-1;
	for(j=0;j<15;j++)
	{
		if(!empty[j])
		{
			if(k!=-1)
			{
				for(int x=0;x<10;x++)
				{
					map[x][k]=map[x][j];
					map[x][j]=0;
				}
				empty[j]=true;
				j=k;
				k=-1;
			}
		}
		else
		{
			k=j;
			while(j+1<15 && empty[j+1])
				j++;
		}
	}

	return;
}

int main(void)
{
	int Game;
	cin>>Game;
	for(int g=1;g<=Game;g++)
	{
		for(int k=9;k>=0;k--)
			cin>>map[k];
		cout<<"Game "<<g<<':'<<endl<<endl;
		int step=0;
		int RemainBalls=150;
		int SumScore=0;
		while(true)
		{
			MaxSize=-1;
			SearchMaxArea();

			if(MaxSize==0 || MaxSize==1)
				break;

			DelMaxArea();
			RefreshMap();
			
			int score=(MaxSize-2)*(MaxSize-2);
			cout<<"Move "<<++step<<" at ("<<MaxR+1<<','<<MaxC+1<<"): ";
			cout<<"removed "<<MaxSize<<" balls of color "<<MaxColor<<", got "<<score<<" points."<<endl;

			RemainBalls-=MaxSize;
			SumScore+=score;
		}
		if(RemainBalls==0)
			SumScore+=1000;
		cout<<"Final score: "<<SumScore<<", with "<<RemainBalls<<" balls remaining."<<endl<<endl;
	}
	return 0;
}
