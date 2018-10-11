#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>
#include <functional>
using namespace std;

char s[30];

int pow(int n, int x)
{
	int ret = 1;
	for (int i = 0; i < x; i++)
		ret = ret * n;

	return ret;
}
int main()
{
	int t; scanf("%d", &t); //A 65 '1' 49
	for (int z = 0; z < t; z++)
	{
		vector<int> v;
		queue<int> q;

		v.clear();
		while (!q.empty())
			q.pop();

		int n, k, x;
		scanf("%d %d", &n, &k);
		scanf("%s", s);
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] >= 65) // 알파벳이라면
				x = s[i] - 55;
			else
				x = s[i] - 48;
			q.push(x);
		}
		/*while (!q.empty())
		{
			printf("%X ", q.front());
			q.pop();
		}*/

		int tmp = 0;
		int cnt = n / 4;

		for (int round = 0; round < cnt; round++)
		{
			
			for (int i = 0; i < n; i++) // 12 / 3(cnt)
			{
				int cur = q.front();
				q.pop();
				q.push(cur);
				tmp += cur * pow(16, (i%cnt));

				if (i%cnt == cnt - 1)
				{
					// 중복검사 여기서
					bool check = true;
					for (int j = 0; j < v.size(); j++)
						if (tmp == v[j])	
							check = false;	//중복이있다면, 넣지않음

					if(check)
						v.push_back(tmp);
					tmp = 0;
				}
			}

			q.push(q.front());
			q.pop();
		}
		sort(v.begin(), v.end(), greater<int>());
		/*for (int j = 0; j < v.size(); j++)
			printf("%d ", v[j]);
		puts("");
		*/
		printf("#%d %d\n", z+1,v[k-1]);

	}

	return 0;
}