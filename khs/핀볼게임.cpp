#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct info {
	int y, x;
};
int map[101][101];
int n;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<info> v[5];

int changedir(int type, int dir)
{
	int ret = 0;
	switch (type) {
	case 1:
		if (dir == 2)
			ret = 1;
		else if (dir == 3)
			ret = 0;
		else	//반대방향
			ret = (dir + 2) % 4;
		break;
	case 2:
		if (dir == 0)
			ret = 1;
		else if (dir == 3)
			ret = 2;
		else	//반대방향
			ret = (dir + 2) % 4;
		break;
	case 3:
		if (dir == 0)
			ret = 3;
		else if (dir == 1)
			ret = 2;
		else	//반대방향
			ret = (dir + 2) % 4;
		break;
	case 4:
		if (dir == 2)
			ret = 3;
		else if (dir == 1)
			ret = 0;
		else	//반대방향
			ret = (dir + 2) % 4;
		break;
	case 5:
		ret = (dir + 2) % 4;
		break;
	}
	return ret;
}

int go(int y, int x, int dir)
{
	int sy = y;
	int sx = x;
	int ny = y;
	int nx = x;
	int cnt = 0;
	//if(end)
	//	return ans;
	//for 문으로 여기서 게임 진행 표기.
	//블랙홀 만나면 or 시작점으로 돌아오면 끝

	while (true)
	{
		ny = ny + dy[dir]; nx = nx + dx[dir];	//방향으로진행

		if (map[ny][nx] == -1 || (ny == sy && nx == sx))
			return cnt;

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
			dir = (dir + 2) % 4;
		//	printf("crush!! at %d %d dir = %d\n", ny, nx, dir);

			cnt++;
			continue;	//벽이라면 방향 바꾸고 다시 진행
		}

		if (1 <= map[ny][nx] && map[ny][nx] <= 5)	//블록들 만나면
		{
			cnt++;
		//	printf("crush!! at %d %d dir = %d\n", ny, nx, dir);

			dir = changedir(map[ny][nx], dir);
			continue;
		}
		if (6 <= map[ny][nx] && map[ny][nx] <= 10)	//웜홀
		{
		//	printf("hole!! at %d %d \n", ny, nx);
			for (int i = 0; i < v[map[ny][nx] - 6].size(); i++)
			{
				if (ny == v[map[ny][nx] - 6][i].y
					&&nx == v[map[ny][nx] - 6][i].x)
					;// printf("hole!!\n");
				else
				{
					int cgy, cgx;
					cgy = v[map[ny][nx] - 6][i].y;
					cgx = v[map[ny][nx] - 6][i].x;
					ny = cgy;
					nx = cgx;
					//printf("hole!! at %d %d dir = %d\n", ny, nx, dir);
					break;
				}
			}
			continue;
		}
		// 웜홀처리 여기서 해주자.
	}
}

int main()
{
	int t; scanf("%d", &t);
	for (int z = 0; z < t; z++)
	{
		scanf("%d", &n);
		for (int i = 0; i < 5; i++)
			v[i].clear();
		memset(map, 0, sizeof(map));
		int ans = 0;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
			{
				scanf("%d", &map[y][x]);
				if (6 <= map[y][x] && map[y][x] <= 10)
					v[map[y][x]-6].push_back({ y,x });
			}

		/*for (int i = 0; i < 5; i++)
		{
			printf("i==%d\n", i);
			for (int j = 0; j < v[i].size(); j++)
			{
				printf("%d %d\n", v[i][j].y, v[i][j].x);
			}
		}*/
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
			{
				if(map[y][x] == 0)
					for (int d = 0; d < 4; d++)	//4방향
					{
						ans = max(ans,go(y, x, d));
					}
			}
			
		printf("#%d %d\n", z + 1, ans);
	}
	return 0;
}