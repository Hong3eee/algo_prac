#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int d[201][201];

int solve(int num, int cnt)
{
	int& ret = d[num][cnt];
	if (ret != -1) return ret;

	if (num == 0) return 1;
	if (cnt == 1) return 1;

	int ans = 0;

	for (int i = 0; i <= num; i++)
		ans = (ans + solve(num - i, cnt - 1)) % 1000000000;

	return ret = ans;
}

int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	memset(d, -1, sizeof(d));
	/*
	for(int i=0;i<=n;i++)
	for(int j=1;j<=k;j++)
	{
	if(i==0 || j==1){
	d[i][j] = 1;
	continue;
	}
	for(int z = 0 ; z<=i; z++)
	d[i][j] = (d[i][j] + d[i-z][j-1]) % 1000000000;
	}
	*/
	printf("%d\n", solve(n, k));
	//	printf("%d\n",d[n][k]);
	system("pause");
	return 0;
}
