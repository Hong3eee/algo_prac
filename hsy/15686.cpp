#include<iostream>
#include<vector>


using namespace std;
void dfs(int start, int depth);
int N, M;
int map[51][51];
bool open[13] = { false, };
int dis[100][13] = {0,};
int result = 1000000;
vector<pair<int, int> > h;
vector<pair<int, int> > c;

int main(void)
{
	cin >> N >> M;
	
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				h.push_back(make_pair(i, j));

			if (map[i][j] == 2)
				c.push_back(make_pair(i, j));
		}
	/*
	for (int i = 1; i <= N; i++)
	{
		cout << endl;
		for (int j = 1; j <= N; j++)
			cout << map[i][j] << " ";
	}
	*/

	for(int i=0; i< h.size(); i++)
		for (int j = 0; j < c.size(); j++)
			dis[i][j] = abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second);


	/*
	for (int i = 0; i < h.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < c.size(); j++)
		{
			cout << dis[i][j] << " ";
		}
	}
	*/
	dfs(0, 0);

	cout << result << endl;
}

void dfs(int start,int depth)
{	
	if (depth == M)
	{	
		int total = 0;
		for (int i = 0; i < h.size(); i++)
		{	
			int min = 1000;
			for (int j = 0; j < c.size(); j++)
			{
				if (open[j] && (dis[i][j] < min))
					min = dis[i][j];
			}
			total += min;
		}
		if (result > total)
			result = total;

		return;
	}

	for (int i = start; i < c.size(); i++)
	{
		open[i] = true;
		dfs(i + 1, depth + 1);
		open[i] = false;
	}
}