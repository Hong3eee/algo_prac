#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int arr[25][25];
int dice[5][5];

int dx[5] = { 0,1,-1,0,0 };// 동1 서2 북3 남4
int dy[5] = { 0,0,0,-1,1 };

int n, m, k, x, y;

void print()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", dice[i][j]);
		puts("");
	}
}

void printmap()
{
	puts("map");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		puts("");
	}
}

void solve(int to)
{
	int nx = x + dx[to];
	int ny = y + dy[to];

	if (0 <= nx && nx < m && 0 <= ny && ny < n)
	{
		switch (to) {
		case 1:
		{
			int tmp = dice[1][2];
			for (int i = 2; i > 0; i--)
				dice[1][i] = dice[1][i - 1];

			int tmp2 = dice[3][1];
			dice[3][1] = tmp;
			dice[1][0] = tmp2;

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[3][1];
			else
			{
				dice[3][1] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			printf("%d\n", dice[1][1]);
			x = nx;
			y = ny;

			break;
		}
		case 2:
		{
			int tmp = dice[1][0];
			for (int i = 0; i < 2; i++)
				dice[1][i] = dice[1][i + 1];

			int tmp2 = dice[3][1];
			dice[3][1] = tmp;
			dice[1][2] = tmp2;

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[3][1];
			else
			{
				dice[3][1] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			printf("%d\n", dice[1][1]);
			x = nx;
			y = ny;
			break;
		}
		case 3:
		{
			int tmp = dice[0][1];
			for (int i = 0; i < 3; i++)
				dice[i][1] = dice[i + 1][1];
			dice[3][1] = tmp;
			// 한칸씩 위로 밈

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[3][1];
			else
			{
				dice[3][1] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			printf("%d\n", dice[1][1]);
			x = nx;
			y = ny;
			break;
		}
		case 4:
		{
			int tmp = dice[3][1];
			for (int i = 3; i > 0; i--)
				dice[i][1] = dice[i - 1][1];
			dice[0][1] = tmp;
			// 한칸씩 밑으로 밈

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[3][1];
			else
			{
				dice[3][1] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			printf("%d\n", dice[1][1]);
			x = nx;
			y = ny;
			break;
		}

		}
	}
}
int main()
{
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	int next;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &next);
		solve(next);
	}

	return 0;
}
