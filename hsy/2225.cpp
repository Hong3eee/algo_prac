#include<iostream>

using namespace std;

int N;
int K;
int dp[201][201];
int main(void)
{
	for(int i=0; i<=200; i++)
		for(int j=0; j<=200; j++)
			dp[i][j] = 1;

	cin >>N >> K;
	for(int i=2; i<=K; i++)
		for(int j=1; j<=N; j++)
			dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000000;

	cout << dp[K][N] % 1000000000 << endl;
}
