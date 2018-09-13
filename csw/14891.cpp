//14891
//톱니바퀴

//14891
//톱니바퀴 핀은 8개 
//좌측부터 1 2 3 4
//N 극은 0 S극은 1
//1은 시계방향 -1은 반시계방향으로 움직임을 나타냄 
//2번과 6번 체크
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;
int wheel[4][8];
int movement[100][2];
int N;

void move(int wheelNum, int direction);
int calcResult();

int main(void)
{
	char input_temp;
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i <4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> input_temp;
			wheel[i][j] = input_temp - '0';
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> movement[i][0] >> movement[i][1];
	}
	for (int i = 0; i < N; i++)
	{
		move((movement[i][0] - 1), movement[i][1]);
	}
	cout << calcResult() << endl;
	system("PAUSE");
	return 0;
}

void move(int wheelNum, int direction)
{
	int temp;
	int i;

	if (wheelNum > 0 && wheelNum<3 && (wheel[wheelNum][2] != wheel[wheelNum + 1][6]))
	{
		move(wheelNum + 1, direction *(-1));
	}

	if (wheelNum > 0 && wheelNum<3 && (wheel[wheelNum][6] != wheel[wheelNum - 1][2]))
	{
		move(wheelNum - 1, direction *(-1));
	}
	if (direction == 1)
	{
		temp = wheel[wheelNum][7];
		for (i = 0; i< 7; i++)
			wheel[wheelNum][i + 1] = wheel[wheelNum][i];
		wheel[wheelNum][0] = temp;
	}
	else
	{
		temp = wheel[wheelNum][0];
		for (i = 7; i > 0; i--)
			wheel[wheelNum][i - 1] = wheel[wheelNum][i];
		wheel[wheelNum][7] = temp;
	}
	return;

}

int calcResult()
{
	int result = 0;
	int point = 1;
	for (int i = 0; i < 4; i++)
	{
		if (wheel[i][0] == 0)
			result += point;
		point *= 2;
	}
	return result;
}