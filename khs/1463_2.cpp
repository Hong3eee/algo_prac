#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int d[1000001];

int main()
{
	int n;
	scanf("%d",&n);

	for(int i=2;i<=n;i++)
	{
		int tmp = 987654321;
		if(i%3 ==0)
			tmp = min(tmp,d[i/3]);

		if(i%2 == 0)
			tmp = min(tmp,d[i/2]);

		tmp = min(tmp,d[i-1]);

		d[i] = tmp+1;
	}

	printf("%d\n",d[n]);

	return 0;
}
