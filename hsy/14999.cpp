#include<iostream>
#include<vector>

using namespace std;

int temp;
int N,M,x,y,K;
int map[20][20]={0,};
int dice[7] = {0,};
int tmp[7] = {0,};
//int dice_dir[7][5] = {{0,0,0,0,0},{0,3,4,2,5},{0,3,4,6,1},{0,6,1,2,5},{0,1,6,2,5},{0,3,4,1,6},{0,3,4,5,2}};
//int dice_top[7] = {0,6,5,4,3,2,1};
int change_dice[5][7] = {{0,0,0,0,0,0,0}, {0,3,2,6,1,5,4}, {0,4,2,1,6,5,3},{0,2,6,3,4,1,5},{0,5,1,3,4,6,2}};
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};
int bottom = 1, top=6;
int main(void)
{
	int t=0;
	int dir = 0;
	vector<int> move;
	cin >> N >> M >> y >> x >> K;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> map[i][j];

	for(int i=0; i<K; i++)
	{
		cin >> temp;
		move.push_back(temp);
	}
	while(t != K)
	{
		dir = move[t++];
		
		if(x+dx[dir] < 0 || x+dx[dir] >=M || y+dy[dir] < 0 ||y + dy[dir] >=N)
			continue;

		x = x + dx[dir];
		y = y + dy[dir];
		
		for(int i=1 ; i<=6; i++)
			tmp[i] = dice[change_dice[dir][i]];			
		
		for(int i=1; i<=6; i++)
			dice[i] = tmp[i];
		
		if(map[y][x] == 0)
			map[y][x] = dice[bottom];
		else
		{
			dice[bottom] = map[y][x];
			map[y][x] = 0;
		}

		cout << dice[top] << endl;
	}
	return 0;
}
