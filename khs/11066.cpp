#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int d[500][500];		// i~j 까지 합쳐서 나오는 파일의 최대 길이 // 이걸 부분합으로 처리..
int d2[500][500];		// i~j 까지 합치는데 나오는 비용의 최솟값

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int z = 0; z < t; z++)	//testcase
	{
		memset(d, 0, sizeof(d));
		memset(d2, 0, sizeof(d2));
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%d", &d[i][i]);

		for (int j= 0; j < k; j++)  // 이 부분을 부분합으로 처리하더라.
			for (int i = j-1; i >= 0; i--)
			{
				int tmp = 9876654321;
				for (int cmp = 1; i + cmp <= j;cmp++)
					tmp = min(tmp, d[j - cmp + 1][j] + d[i][j - cmp]);

				d[i][j] = tmp;
			}

		for (int j = 0; j < k; j++)  
			for (int i = j - 1; i >= 0; i--)
			{
				int tmp = 9876654321;
				for (int cmp = 1; i + cmp <= j; cmp++)
				{
						tmp = min(tmp, d[i][j] + d2[j - cmp + 1][j] + d2[i][j - cmp]);
				}
				d2[i][j] = tmp;
			}
		
		printf("%d\n", d2[0][k-1]);
	}


	return 0;
}
