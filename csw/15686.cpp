 warning(disable:4996)
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int N;
int M;//최대로 수익을 낼 수 있는 치킨집의 갯수
int map[51][51];
int answer;
bool check[15] = { false };

vector<pair<int, int>> kkokko;
vector<pair<int, int>> home;

void dfs(int num, int cnt);	
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				home.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)
			{
				kkokko.push_back(make_pair(i, j));
			}
		}
	}
	answer = 9999999999;
	dfs(0, 0);
	cout << answer << endl;
	return 0;
}

void dfs(int num, int cnt)
{
	if (num > kkokko.size)
		return;
	if (cnt == M)
	{
		int sumDist = 0, Dist = 999999999;
		for (int i = 0; i < home.size; i++)
		{
			for (int j = 0; j < kkokko.size; j++)
			{
				if (check[j])
				{
					int temp_dist = abs(home[i].first - kkokko[j].first) + abs(home[i].second - kkokko[j].second);
					if (Dist > temp_dist)
						Dist = temp_dist;
				}
			}
			sumDist += Dist;
		}
		if (answer > sumDist)
			answer = sumDist;
	}
	check[num] = true;
	dfs(num + 1, cnt + 1);

	check[num] = false;
	dfs(num + 1, cnt);

	return;
}
