#include<iostream>

using namespace std;

int main(void)
{
	int dp[1000001];
	int N;
	
	for(int i=2; i<1000001; i++)
		dp[i] = 10000000;

	dp[1] = 0;
	cin >> N;
	
	for(int i=1; i<N; i++)
	{
		if(i+1 <= N)
			dp[i+1] = min(dp[i+1], dp[i] +1);
		if(i*2 <= N)
			dp[i*2] = min(dp[i*2], dp[i] +1);
		if(i*3 <= N)
			dp[i*3] = min(dp[i*3], dp[i] +1);
	}

	cout << dp[N] << endl;
}
