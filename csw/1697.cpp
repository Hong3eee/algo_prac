//1697
//숨바꼭질
//bfs
#include<iostream>
#include<queue>
using namespace std;
int N;
int M;
int dx[3] = {-1, 0, 1};
int result = 9999999;
bool check[100001] = {false};
typedef struct _cntnum
{
	int cnt;
	int num;
}data;
queue<data> q;

void bfs()
{
	data item;
	data temp;
	check[N] = true;
	item.cnt = 0;
	item.num = N;
	q.push(item);
	while(!(q.empty()))
	{
		item = q.front();
		q.pop();
		if(item.num == M)
		{
			if(result > item.cnt)
			{ 
				result = item.cnt;
			}
			break;
		}
		++(item.cnt);
		for(int i = 0; i < 3; i++)
		{
			if(i == 1)
			{
				if((item.num*2) < 100001 &&!check[item.num*2])//이프문 조건 순서주의 
				{
					temp.cnt = item.cnt;
					temp.num = (item.num * 2);
					q.push(temp);
					check[temp.num] = true;
				}
			}
			else if(i == 0)
			{
				if(item.num > 0 && !check[item.num + dx[i]])
				{
					temp.cnt = item.cnt;
					temp.num = (item.num + dx[i]);
					q.push(temp);
					check[temp.num] = true;
				}
			}
			else
			{
					if(item.num < 100000 &&!check[item.num + dx[i]])
				{
					temp.cnt = item.cnt;
					temp.num = (item.num + dx[i]);
					q.push(temp);
					check[temp.num] = true;
				}
			}

		}
			
	}

	return;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	if (N == M)
		result = 0;
	else
		bfs();

	cout << result << endl;
	return 0;
}
//dfs로 시간초과 발생 
/*
#include<iostream>
using namespace std;
int N;
int M;
int result = 99999999;

void DFS(int cnt, int n)
{
	if(n == M)
	{
		if(result > (cnt-1))
			result = cnt-1;
		return;
	}
	if(n<M)
	{
		DFS(cnt+1, 2*n);
		DFS(cnt+1, n+1);
	}
	else
	{
		DFS(cnt+1, n-1);
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	DFS(0,N);
	cout << result << endl;
	return 0;
}
*/