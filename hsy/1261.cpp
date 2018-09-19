#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct pos{
	int y;
	int x;
	int value;
	pos(int _y=0, int _x=0, int _value=0) : y(_y), x(_x), value(_value){}
};

bool operator<(pos a, pos b){
	return a.value>b.value;
}

int dx[4] ={0,-1,0,1};
int dy[4] ={-1,0,1,0};
int N, M;
int map[101][101]={0,};
bool check[101][101]={false,};
priority_queue<pos> pq;

int main(void)
{
	int y,x,v;
	pos f;
	
	cin >> M >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d",&map[i][j]);
	
	pq.push(pos(1,1,0));
	check[1][1] = true;
	
	while(!pq.empty())
	{
		f = pq.top();
		pq.pop();
		for(int i=0; i<4; i++)
		{
			y = f.y + dy[i];
			x = f.x + dx[i];
			if(x <1 || y < 1 || x > M || y>N || check[y][x])
				continue;
			pq.push(pos(y,x,f.value+map[y][x]));
			map[y][x] = f.value+map[y][x];
			check[y][x] = true;
		}
		if(check[N][M])
			break;
	}
	cout << map[N][M] << endl;
	return 0;
}

