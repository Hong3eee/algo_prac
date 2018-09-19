
#include<iostream>

using namespace std;

int N, M;
int map[8][8];
int camera[8];
int camera_pos[8][2];
int result = 65;
int temp = 0;
int q = 0;
void fill_out(int num, int dir, bool check);
void DFS(int depth);
int main(void)
{
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 6 && map[i][j] != 0)
			{
				camera[temp] = map[i][j];
				camera_pos[temp][0] = i;
				camera_pos[temp][1] = j;
				temp++;
			}
		}
	DFS(0);
	cout << result << endl;
}
void DFS(int depth)
{
	if (depth == temp)
	{
		q++;
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
					cnt++;
			}
		}
		
		if (result > cnt)
			result = cnt;
		
		return;
	}
	switch (camera[depth])
	{
	case 5:
		fill_out(depth, 0, true);
		fill_out(depth, 1, true);
		fill_out(depth, 2, true);
		fill_out(depth, 3, true);
		DFS(depth + 1);
		fill_out(depth, 0, false);
		fill_out(depth, 1, false);
		fill_out(depth, 2, false);
		fill_out(depth, 3, false);
		break;
	
	case 4:
		for (int i = 0; i < 4; i++)
		{
			fill_out(depth, i % 4, true);
			fill_out(depth, (i+1) % 4, true);
			fill_out(depth, (i+2) % 4, true);
			DFS(depth + 1);
			fill_out(depth, i % 4, false);
			fill_out(depth, (i + 1) % 4, false);
			fill_out(depth, (i + 2) % 4, false);
		}
		break;
	
	case 3:
		for (int i = 0; i < 4; i++)
		{
			fill_out(depth, i % 4, true);
			fill_out(depth, (i + 1) % 4, true);
			DFS(depth + 1);
			fill_out(depth, i % 4, false);
			fill_out(depth, (i + 1) % 4, false);
		}
		break;

	case 2:
		for (int i = 0; i < 2; i++)
		{
			fill_out(depth, i % 4, true);
			fill_out(depth, (i + 2) % 4, true);
			DFS(depth + 1);
			fill_out(depth, i % 4, false);
			fill_out(depth, (i + 2) % 4, false);
		}
		break;
	case 1:
		for (int i = 0; i < 4; i++)
		{		
			fill_out(depth, i, true);
			DFS(depth + 1);
			fill_out(depth, i, false);
		}	
		break;
	}
}

void fill_out(int num, int dir, bool check)
{
	int i = camera_pos[num][0];
	int j = camera_pos[num][1];
	switch (dir)
	{
	case 0:
		for (i=i-1; i >= 0; i--)
		{
			if (map[i][j] == 6)
				break;
			else if(map[i][j] !=0 && map[i][j] !=6 && map[i][j] !=9)
				continue;
			
			if (check)
				map[i][j] = 9;
			else
				map[i][j] = 0;
		}
		break;

	case 1:
		for (j=j-1; j >= 0; j--)
		{
			if (map[i][j] == 6)
				break;
			else if(map[i][j] !=0 && map[i][j] !=6 && map[i][j] !=9)
				continue;
			
			if (check)
				map[i][j] = 9;
			else
				map[i][j] = 0;
		}
		break;

	case 2:
		for (i=i+1; i < N; i++)
		{
			if (map[i][j] == 6)
				break;
			else if(map[i][j] !=0 && map[i][j] !=6 && map[i][j] !=9)
				continue;

			if (check)
				map[i][j] = 9;
			else
				map[i][j] = 0;
		}
		break;

	case 3:
		for (j=j+1; j < M; j++)
		{
			if (map[i][j] == 6)
				break;
			else if(map[i][j] !=0 && map[i][j] !=6 && map[i][j] !=9)
				continue;
			
			if (check)
				map[i][j] = 9;
			else
				map[i][j] = 0;
		}
		break;
	}
}
