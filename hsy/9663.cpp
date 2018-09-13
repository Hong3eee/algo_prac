#include<iostream>

using namespace std;
int cnt=0;
int N;
int board[15]={0,};

void DFS(int depth);
bool check(int depth);
int main(void)
{
	cin >> N;	
	DFS(0);
	cout << cnt << endl;
}

void DFS(int depth)
{
	if(depth == N)
	{
		cnt++;
		return;
	}
	for(int i=0; i<N; i++)
	{
		board[depth] = i;
		if(check(depth))
			DFS(depth+1);
		board[depth] = 0;
	}
}

bool check(int depth)
{
	for(int i=0; i<depth; i++)
	{
		if(board[i] == board[depth])
			return false;
		if(depth-i == abs(board[depth] - board[i]))
			return false;
	}
	return true;
}








