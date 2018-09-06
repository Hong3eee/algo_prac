//2309
//일곱난쟁이
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];
int answer[7];
bool arrCheck[10] = {false};
bool check = false;

void calc(int cnt, int num);

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	calc(0,0);
	sort(answer, answer+7);
	for(int i = 0; i < 7; i++)
	{
		cout << answer[i] <<endl;
	}
	return 0;
}
void calc(int cnt, int num)
{
	int i = 0, j = 0;
	if(check)
		return;
	if(cnt > 9)
		return;
	if(num == 7)
	{
		int sum = 0;
		for(; i < 9; i++)
		{
			if(arrCheck[i])
				sum += arr[i];
		}
		if(sum == 100)
		{
			for(i = 0; i < 9;i++)
			{
				if(arrCheck[i])
				{
					answer[j++] = arr[i];
				}
			}
			check = true;
			return;
		}		
	}
	arrCheck[cnt] = true;
	calc(cnt+1, num+1);	
	arrCheck[cnt] = false;
	calc(cnt+1, num);	
	return;
}