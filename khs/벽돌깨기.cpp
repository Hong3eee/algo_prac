#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, w, h;
int map[16][13];
int arr[16][13];	//tmp_map
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[13];	//���յ� ����
int ans = 987654321;
int calc()
{
	int ret = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (arr[i][j] != 0)
				ret++;

	return ret;
}
void init_map()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			arr[i][j] = map[i][j];
}

void del(int y, int x)
{
	int cnt = arr[y][x];
//	printf("cnt %d\n", cnt);
	arr[y][x] = 0;
	if (cnt == 0 || cnt == 1) return; // �Ұ� ����

	for (int i = 0; i < 4; i++)
	{
		int ny = y, nx = x;
		for (int k = 1; k < cnt; k++)
		{
			ny = ny + dy[i];
			nx = nx + dx[i];
			if (0 <= ny && ny < h && 0 <= nx && nx < w)
				del(ny, nx);
		}
	}
}

void fill()
{
	//3�� ���� vs ť ���⼱ 3����������
	for (int j = 0; j < w; j++)
		for (int i = h - 1; i >0; i--)
		{
			if (arr[i][j] == 0)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (arr[k][j] != 0)
					{
						arr[i][j] = arr[k][j];
						arr[k][j] = 0;
						break;
					}
				}
			}
		}
}

void simul()
{
	init_map();// �ʺ���.

	for (int i = 0; i < n; i++)
	{
		int target = visited[i];
		for (int y = 0; y < h; y++)
		{
			if (arr[y][target] != 0)
			{
				del(y, target);
				break;
			}
		}
		fill();// ���� ������� ä����.
	}
}

void solve(int cnt)
{
	if (cnt == n)	// n���� ������ �ߴٸ�,
	{
		simul();
		int x = calc();
		ans = min(ans, x);
		return;
	}
	for (int i = 0; i < w; i++)
	{
		visited[cnt] = i;
		solve(cnt + 1);
		visited[cnt] = -1;
	}
}
int main()
{
	int t; scanf("%d", &t);
	for (int z = 0; z < t; z++)
	{
		memset(map, 0, sizeof(map));
		memset(visited, -1, sizeof(visited));
		ans = 987654321;

		scanf("%d %d %d", &n, &w, &h);
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				scanf("%d", &map[y][x]);

		solve(0);
		printf("#%d %d\n", z + 1, ans);
	}
	return 0;
}