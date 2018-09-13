//9019
//dslr
//1.D: D 는 n을 두 배로 바꾼다.결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다.그 결과 값(2n mod 10000)을 레지스터에 저장한다.
//2.S : S 는 n에서 1 을 뺀 결과 n - 1을 레지스터에 저장한다.n이 0 이라면 9999 가 대신 레지스터에 저장된다.
//3.L : L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다.이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
//4.R : R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다.이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.

#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<string>//나 스트링 처음써봄 ㅎㅎ

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