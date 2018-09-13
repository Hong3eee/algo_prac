#include <cstdio>
#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> q[5];

void rotate(int ,int);

void goright(int num,int dir)
{
	if(num==4)
		rotate(num,dir);
	else
	{
		if(q[num][2] != q[num + 1][6])
			goright(num + 1 , -1 * dir);
		rotate(num,dir);
	}
}

void goleft(int num,int dir)
{
	if(num==1)
		rotate(num,dir);
	else
	{
		if(q[num][6] != q[num - 1][2])
			goleft(num - 1 , -1 * dir);
		rotate(num,dir);
	}
}

void rotate(int num,int dir)
{
	if(dir == 1)
	{
		int back = q[num].back();
		q[num].push_front(back);
		q[num].pop_back();
	}
	else
	{
		int front = q[num].front();
		q[num].push_back(front);
		q[num].pop_front();
	}
}

void solve(int num,int dir)
{
	if(num==4)
	{
		if(q[num][6] != q[num - 1][2])
			goleft(num - 1 , -1 * dir);
	}
	else if(num==1)
	{
		if(q[num][2] != q[num + 1][6])
			goright(num + 1 , -1 * dir);
	}
	else
	{
		if(q[num][2] != q[num + 1][6])
			goright(num + 1 , -1 * dir);

		if(q[num][6] != q[num - 1][2])
			goleft(num - 1 , -1 * dir);
	}

	rotate(num,dir);


	return ;
}

int main(){
	int x;

	for(int i=1;i<=4;i++)
	{
		for(int j=0;j<8;j++)
		{
			scanf("%1d",&x);
			q[i].push_back(x);
		}
	}

	int k;
	int num,dir;
	scanf("%d",&k);

	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&num,&dir);
		solve(num,dir);
	}


	int ans = 0;

	for(int i=4;i>=1;i--)
	{
		ans = ans + q[i][0];

		if(i==1)
			break;
		ans = ans << 1;
	}

	printf("%d\n",ans);

	return 0;
}
