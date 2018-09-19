#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int map[105][105];
int check[105][105];

int n, m;

typedef struct info {
	int y, x,cnt;	//cnt = 가중치
	info(int _y, int _x, int _cnt) :
		y(_y), x(_x),cnt(_cnt) {};
	bool operator <(info A)const { return cnt > A.cnt; }

}info;
/*
struct cmp {
	bool operator()(info t, info u) {
		return t.cnt > u.cnt;
	}
};
*/
void bfs(int y, int x)
{
	priority_queue<info> q;
//	priority_queue<info, vector<info>, cmp > q;
	q.push(info(y, x,0));
	
	check[y][x] = 1;

	while (!q.empty())
	{
		info cur =q.top();
		q.pop();
//		printf("%d %d %d\n", cur.y, cur.x,cur.cnt);
		if (cur.y == n && cur.x == m)
			printf("%d\n", cur.cnt);

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (1 <= ny && ny <= n && 1 <= nx && nx <= m)
			{
				if (check[ny][nx] == 0)
				{	
					q.push(info(ny, nx, cur.cnt + map[ny][nx]));
					check[ny][nx] = 1;
				}
			}
		}
	}
	return;
}
int main()
{
	scanf("%d %d", &m, &n);
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			scanf("%1d", &map[y][x]);

	memset(check, 0, sizeof(check));
	bfs(1, 1);
	return 0;
}
