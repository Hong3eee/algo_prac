#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int map[700][700];
int dy[4] = { -1,1,0,0 };	//상하좌우
int dx[4] = { 0,0,-1,1 };
struct info {
	int life, y, x;
};
int main()
{
	int t; scanf("%d", &t);
	for (int z = 0; z < t; z++)
	{
		queue<info> q[11];
		for (int i = 0; i < 11; i++)
			while (!q[i].empty()) 
				q[i].pop();

		int n, m, k;

		memset(map, 0, sizeof(map));
		int ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &map[i + 300][j + 300]);
				if (map[i + 300][j + 300])
					q[map[i + 300][j + 300]].push({ map[i + 300][j + 300] * 2,i+300,j+300 });
			}

		for (int time = 0; time <= k; time++)
		{
			for (int life = 10; life >= 1; life--)
			{
				int siz = q[life].size();
				for (int size = 0; size < siz; size++)
				{
					info cur = q[life].front(); q[life].pop();
					if (cur.life > life)
					{
						if (map[cur.y][cur.x] > 0)	//초기상태 -> 비활성
						{
							map[cur.y][cur.x] = -map[cur.y][cur.x];
							ans++;
						}
						q[life].push({ cur.life - 1,cur.y,cur.x });
					}
					else if (cur.life == life)	// 비활성 -> 활성
					{
						q[life].push({ cur.life - 1,cur.y,cur.x });

						for (int i = 0; i < 4; i++)
						{
							int ny = cur.y + dy[i]; int nx = cur.x + dx[i];
							if (map[ny][nx]) continue;
							map[ny][nx] = life;
							q[life].push({ life * 2,ny,nx });
						}
					}
					else if (life > cur.life && cur.life)	// 활성상태에서 생명력줄여줌
						q[life].push({ cur.life - 1,cur.y,cur.x });
					else		// 활성상태에서 생명력이 다 없어지면,
						ans--;
				}
			}

		}

		printf("#%d %d\n", z + 1, ans);
	}
	return 0;
}