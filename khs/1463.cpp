#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int d[1000001];

int solve(int n)
{
	int& ret = d[n];
	if(ret != -1)
		return ret;

	if(n < 2)
		return ret = 0;

	int tmp = 987654321;
	if(n%3 == 0)
		tmp = min(tmp,solve(n/3));

	if(n%2 == 0)
		tmp = min(tmp,solve(n/2));

	tmp = min(tmp,solve(n-1));

	return ret = tmp+1;
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(d,-1,sizeof(d));

	printf("%d\n",solve(n));
	return 0;
}
