#include<iostream>

using namespace std;

int dp[1000001];
int N;

int dfs(int n){
	if(n==1) return 0;
	if(dp[n]!=-1) return dp[n];

	int result = dfs(n-1) + 1;
	if(n%2 == 0) result = min(result, dfs(n/2) +1);
	if(n%3 == 0) result = min(result, dfs(n/3) + 1);
	dp[n] = result;
	return dp[n];
}
int main(void)
{
	for(int i=0; i<1000001; i++)
		dp[i] = -1;
	dp[1] = 0;
	cin >> N;
	dfs(N);
	cout << dp[N]<<endl;
}
