#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

bool check[10000];

struct info {
	int cur;
	string path;
	info(int _cur, string _prev) :
		cur(_cur), path(_prev) {};
};
string bfs(int start,int goal)
{
	queue<info> q;
	q.push(info(start, ""));
	check[start] = true;

	while (!q.empty())
	{
		info cur = q.front();
		q.pop();
		int now = cur.cur;
		string path = cur.path;
		if (now == goal)
			return path;

		// D=1, S=2, L=3, R=4.
		int next = (now * 2) % 10000;
		if (!check[next]) // 방문 하지 않은 상태라면
		{
			q.push(info(next, path + "D"));
			check[next] = true;
		}

		next = now == 0 ? 9999 : (now - 1);
		if (!check[next]) // 방문 하지 않은 상태라면
		{
			q.push(info(next, path + "S"));
			check[next] = true;
		}

		int d1 = now / 1000, d2 = (now / 100) % 10, d3 = (now / 10) % 10, d4 = now % 10;
		next = d2 *1000 + d3 * 100 + d4 * 10 + d1;
		if (!check[next]) // 방문 하지 않은 상태라면
		{
			q.push(info(next, path + "L"));
			check[next] = true;
		}

		next = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
		if (!check[next]) // 방문 하지 않은 상태라면
		{
			q.push(info(next, path + "R"));
			check[next] = true;
		}
	}

	return "error";
}


int main()
{
	int t;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++)
	{
		memset(check, false, sizeof(check));
		int a, b;
		scanf_s("%d %d", &a, &b);
		string ans = bfs(a, b);
		cout << ans << endl;
		system("pause");
	}

	return 0;
}
