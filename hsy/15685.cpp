#include<iostream>
#include<vector>

#define SIZE 101
using namespace std;

int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0,-1,0,1 };

int main(void)
{
	int board[SIZE][SIZE];
	int N;
	int c = 0;
	int x, y, d, g;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = 0;

	cin >> N;
	
	while (N--)
	{
		cin >> x >> y >> d >> g;
		
		vector<int> v;
		v.push_back(d);
		board[y][x] = 1;
		x = x + dx[d];
		y = y + dy[d];
		board[y][x] = 1;

		for (int i = 1; i <= g; i++)
		{
			for (int j = v.size() - 1; j >= 0; j--)
			{
				x = x + dx[(v[j]+1)%4];
				y = y + dy[(v[j]+1)%4];
				board[y][x] = 1;
				v.push_back((v[j] + 1) % 4);
			}
		}
	}

	for(int i=0; i<SIZE-1; i++)
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
				c++;
		}

	cout << c << endl;
}
