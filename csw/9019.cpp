//9019
//dslr
//1.D: D �� n�� �� ��� �ٲ۴�.��� ���� 9999 ���� ū ��쿡�� 10000 ���� ���� �������� ���Ѵ�.�� ��� ��(2n mod 10000)�� �������Ϳ� �����Ѵ�.
//2.S : S �� n���� 1 �� �� ��� n - 1�� �������Ϳ� �����Ѵ�.n�� 0 �̶�� 9999 �� ��� �������Ϳ� ����ȴ�.
//3.L : L �� n�� �� �ڸ����� �������� ȸ������ �� ����� �������Ϳ� �����Ѵ�.�� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d2, d3, d4, d1�� �ȴ�.
//4.R : R �� n�� �� �ڸ����� ���������� ȸ������ �� ����� �������Ϳ� �����Ѵ�.�� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d4, d1, d2, d3�� �ȴ�.

#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<string>//�� ��Ʈ�� ó���ẽ ����

using namespace std;
typedef struct _data
{
	int num;	
	string movement;
}item;

int N;
bool check[10000] = { false };
int inputArr[10000][2];

void BFS(int N);
int calcD(int num);
int calcS(int num);
int calcL(int num);
int calcR(int num);

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> inputArr[i][0] >> inputArr[i][1];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i] = false;
		}
		BFS(i);
	}
	system("PAUSE");
	return 0;
}
void BFS(int N)
{
	queue<item> Q;
	item temp;
	item temp2;
	int numTemp;
	string stringTemp;
	temp.num = inputArr[N][0];
	temp.movement = "";
	Q.push(temp);
	check[temp.num] = true;

	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if ((temp.num == inputArr[N][1]))
		{
			cout << temp.movement << endl;
			break;
		}
		numTemp = calcD(temp.num);
		if(!(check[numTemp]))
		{
			stringTemp = temp.movement + "D";
			temp2.num = numTemp;
			temp2.movement = stringTemp;
			Q.push(temp2);
			check[numTemp] = true;
		}
		numTemp = calcS(temp.num);
		if (!(check[numTemp]))
		{
			stringTemp = temp.movement + "S";
			temp2.num = numTemp;
			temp2.movement = stringTemp;
			Q.push(temp2);
			check[numTemp] = true;
		}
		numTemp = calcL(temp.num);
		if (!(check[numTemp]))
		{
			stringTemp = temp.movement + "L";
			temp2.num = numTemp;
			temp2.movement = stringTemp;
			Q.push(temp2);
			check[numTemp] = true;
		}
		numTemp = calcR(temp.num);
		if (!(check[numTemp]))
		{
			stringTemp = temp.movement + "R";
			temp2.num = numTemp;
			temp2.movement = stringTemp;
			Q.push(temp2);
			check[numTemp] = true;
		}
	}
	return;
}

int calcD(int num)
{
	(num) *= 2;
	if ((num) >= 10000)
		(num) %= 10000;
	return num;
}
int calcS(int num)
{
	if ((num) == 0)
		(num) = 9999;
	else
		(num) -= 1;
	return num;
}
int calcL(int num)
{
	num = (num % 1000) * 10 + num / 1000;
	return num;
}
int calcR(int num)
{

	int temp;
	temp = (num) % 10;
	(num) = (num) / 10;
	(num) = (num) + (temp * 1000);
	return num;
}