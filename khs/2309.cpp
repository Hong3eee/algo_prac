#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool check[10];
int arr[9];

void calc()
{
	int sum = 0;
	for(int i=0;i<9;i++)
		if(check[i])
			sum += arr[i];

	if(sum == 100)
	{
		vector<int> v;
		for(int i=0;i<9;i++)
			if(check[i])
				v.push_back(arr[i]);

		sort(v.begin(),v.end());

		for(int i=0;i<v.size();++i)
			printf("%d\n",v[i]);
	}
	return ;
}

void solve(int idx,int cnt)
{
	if(idx > 9)
		return;

	if(cnt == 7)
	{
		calc();
		return;
	}

	for(int i = idx;i<9;i++)
	{
		check[i] = true;
		solve(i+1,cnt+1);
		check[i] = false;
	}
}

int main()
{
	for(int i =0;i<9;i++)
		scanf("%d",&arr[i]);

	solve(0,0);
	return 0;
}
