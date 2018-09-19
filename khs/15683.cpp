#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int arr[8][8];
int dy[8] = {1,0,-1,0,1,0,-1,0};
int dx[8] = {0,1,0,-1,0,1,0,-1};
int ans = 987654321;
int n,m;
vector<pair<int,int> > v;
int dir[8];
int tmp[8][8];

void fill(int y,int x,int direction){
	while( (0<= y && y < n) && (0<=x && x < m) ){
		if(arr[y][x] == 6)
			break;
		else
			tmp[y][x] = -1;

		y += dy[direction];
		x += dx[direction];
	}
	return ;
}
void init()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			tmp[i][j] = arr[i][j];
}
int simul(){

	init();

	int ret = 0;
	for(int i =0;i<v.size();i++)
	{
		int val,y,x;
		y = v[i].first;
		x = v[i].second;
		val = arr[y][x];

		switch (val){
			case 1:
				fill(y,x,dir[i]);
				break;
			case 2:
				fill(y,x,dir[i]);
				fill(y,x,dir[i]-2);
				break;
			case 3:
				fill(y,x,dir[i]);
				fill(y,x,dir[i]-1);
				break;
			case 4:
				fill(y,x,dir[i]);
				fill(y,x,dir[i]-1);
				fill(y,x,dir[i]-2);
				break;
			case 5:
				fill(y,x,dir[i]);
				fill(y,x,dir[i]-1);
				fill(y,x,dir[i]-2);
				fill(y,x,dir[i]-3);
				break;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(tmp[i][j] ==0) ret++;
	return ret;
}

void solve(int idx){
	if(idx == v.size()) {
		ans = min(ans,simul());
		return;
	}

	for(int i =4;i<8;i++)
	{
		dir[idx] = i;
		solve(idx+1);
	}

}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] != 6 && arr[i][j] != 0)
				v.push_back(make_pair(i,j));
		}

	solve(0);

	printf("%d\n",ans);

	return 0;
}
