#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

int m[101][101];
int tmp[101][101];
int orgx,orgy,d,g;

void dragon(int y,int x,int gen){ //x,y -> y,-x 

	//gen-1 세대 처리
	if(gen == g)
		return;

	int temp[101][101]={0,};

	for(int b = 0;b<=100;b++)
		for(int a = 0;a<=100;a++)
		{
			if(tmp[b][a] == 1)
			{
				temp[b][a] = 1;
				temp[a-x+y][x-b+y] = 1;
			}
		}

	int nexty = orgx - x + y;
	int nextx = x - orgy + y;

//	cout << gen << "<- gen " << nexty << " <- nexty " << nextx <<" <- nextx " <<endl;

	for(int b = 0;b<=100;b++)
		for(int a = 0;a<=100;a++)
		{
			if(temp[b][a] == 1)
				tmp[b][a] = 1;
			else
				tmp[b][a] = 0;
		}
	dragon(nexty,nextx,gen+1);

	return ;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		memset(tmp,0,sizeof(tmp));
		cin >> orgx >> orgy >> d >> g;

		tmp[orgy][orgx] = 1;
		tmp[orgy+dy[d]][orgx+dx[d]] = 1;

		dragon(orgy + dy[d],orgx + dx[d],0);

		for(int y = 0 ;y<=100;y++)
			for(int x = 0 ;x<=100;x++)
			{
				//m[y][x] = m[y][x] || tmp[y][x];
				if(tmp[y][x] + m[y][x] >= 1)
					m[y][x] = 1;
			}

	}

	// 정사각형의 갯수를 여기서 센다.

	/*
	for(int y = 0 ;y<100;y++)
	{
		for(int x = 0 ;x<100;x++)
			printf("%d ",m[y][x]);
		puts("");
	}
*/

	int ans = 0;
	for(int y = 0 ;y<100;y++)
		for(int x = 0 ;x<100;x++)
			if(m[y][x] == 1 && m[y+1][x] == 1 && m[y][x+1] == 1 && m[y+1][x+1] == 1)
				ans++;

	cout << ans << endl;

	return 0;
}
