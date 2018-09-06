#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int map[101][101]; // 1 ~ 100 idx
int tmp[101][101]; // 1 ~ 100 idx

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };	// N E S W, 순서

char change[10001]; // 방향 변화 정보 가지고있는 배열
deque<pair<int,int> > dq;

int n;

void init_map()
{
	memset(tmp,0,sizeof(tmp));

	for(int i =1;i<=n;i++)
		for(int j =1;j<=n;j++)
			tmp[i][j] = map[i][j];

	for(int i =0;i<dq.size();i++)
		tmp[dq[i].first][dq[i].second] = 2;	//뱀 본체 게임판에 찍어줌

	return ;
}

bool simul(int direction)
{
	init_map();

	int y = dq.front().first;
	int x = dq.front().second;

	int ny = y + dy[direction];
	int nx = x + dx[direction];

	if( (0 < ny && ny <= n) && (0 < nx && nx <= n) )
	{
		if(tmp[ny][nx] == 2)	// 머리가 자신의 몸을 만남
		   return false;	
		else if(tmp[ny][nx] == 1) // 사과
		{
			dq.push_front(make_pair(ny,nx));
			map[ny][nx] = 0;
		}
		else
		{
			dq.push_front(make_pair(ny,nx));
			dq.pop_back();
		}

	}
	else
		return false;

	return true;
}

int main()
{
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int y,x;
		scanf("%d %d",&y,&x);
		map[y][x] = 1;
	}

	int l;
	scanf("%d",&l);
	for(int i=0;i<l;i++)
	{
		int t;
		char c;

		scanf("%d %c",&t,&c);
		change[t] = c;
	}

	int direction = 1; //E 방향 초기화
	dq.push_back(make_pair(1,1)); // 뱀 초기 위치

	for(int t = 1;t<10001;t++)
	{
		bool check = simul(direction);
//		printf("check = %d t = %d\n",check,t);
//		for(int i =0;i<dq.size();i++)
//			printf("dq y = %d x = %d\n",dq[i].first,dq[i].second);

		if(!check)		// 게임 오버
		{
			printf("%d\n",t);
			break;
		}

		if(change[t] == 'D')
			direction = (direction + 1) %4;
		else if(change[t] == 'L')
			direction = (direction  == 0) ? 3 : direction - 1 ;

	}

	return 0;
}
