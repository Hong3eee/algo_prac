#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[16][16];
int n;
int ans;
bool check(int y, int x)
{
	int tmp = 0;

	while ( 1 <= y - tmp && y - tmp <= n) 
	{
		if (arr[y-tmp][x] == 1)
			return false;
		tmp++;
	}

	tmp = 0;
	while (1 <= y - tmp && y - tmp <= n &&
		1 <= x - tmp && x - tmp <= n)
	{
		if (arr[y - tmp][x - tmp] == 1)
			return false;
		tmp++;
	}

	tmp = 0;
	while (1 <= y - tmp && y - tmp <= n &&
		1 <= x + tmp && x + tmp <= n)
	{
		if (arr[y - tmp][x + tmp] == 1)
			return false;
		tmp++;
	}

	return true;
}
void solve(int next)
{
	if (next == n ) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (check(next+1, i))
		{
			printf("y = %d i = %d ans = %d \n", next + 1, i,ans);
			
			arr[next+1][i] = 1;
			solve(next + 1);
			arr[next+1][i] = 0;
		}
	}
}

int main()
{
	scanf_s("%d", &n);
	solve(0);

	printf("%d\n", ans);
	system("pause");
	return 0;
}
