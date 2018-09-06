//1463
//1로 만들기 
//DP

#include<iostream>
using namespace std;
int N;
int arr[1000001] = {0};
int DP(int n)
{
	int tmp = 0;
	if(n<=1)
		return 0;
	if( arr[n] > 0) return arr[n];
	
	arr[n] = DP(n-1) + 1;

	if(n%2 == 0)
	{
		tmp = DP(n/2)+1;
		if(arr[n] > tmp)
			arr[n] = tmp;
	}
	if(n%3 == 0)
	{
		tmp = DP(n/3)+1;
		if(arr[n] > tmp)
			arr[n] = tmp;
	}
	return arr[n];
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	DP(N);
	cout << arr[N]<< endl;
	return 0;
}
/*int N;
int result = 999999;

void calc(int n);
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	calc(N);
	cout << result << endl;
	return 0;
}

void calc(int n)
{
	if(n<=1)
		return;
	if(n%3 == 0)
	{
		++result;
		calc(n/3);
	}
	if(n%2 == 0)
	{
		++result;
		calc(n/2);	
	}
	else
	{
		++result;
		calc(n-1);
	}
	return;
}*/