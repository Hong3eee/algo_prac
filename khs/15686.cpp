#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

int ans = 987654321;
int arr[51][51];
bool check[15];
int n,m;
int len=0;
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;

// size == n/2 일때 팀 능력치 계산하는 함수
int calc(){
	
//   for(int i=0;i<len;i++)
//	   if(check[i] == true)
//			printf("first -> %d  second -> : %d\n",chicken[i].first,chicken[i].second);

   int sum=0;
   for(int i=0;i<house.size();i++)
   {

	   int y = house[i].first;
	   int x = house[i].second;

	   int chicken_len = 987654321;

 	  for(int j=0;j<len;j++)
		   if(check[j] == true)
				chicken_len = min(chicken_len, abs(y-chicken[j].first) + abs(x-chicken[j].second) );

	  sum += chicken_len;
   }

//	printf("sum = %d\n",sum);
//	puts("");

	return sum;
}

//그룹을 처음부터 끝까지 구해주는 재귀함수
void makegroup(int lastidx,int size){
	if(size == m)
	{
		ans = min(ans,calc());
		return ;
	}

	for(int i = lastidx + 1;i<len;i++)
	{
		check[i] = true;

		makegroup(i,size+1);
		check[i] = false ;
	}
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 2)
				chicken.push_back(make_pair(i,j));
			else if(arr[i][j] == 1)
				house.push_back(make_pair(i,j));
		}

	len = chicken.size();

	for(int i=0;i<len;i++) 
	{		
		check[i] = true;

		makegroup(i,1);
		check[i] = false ;
	}
	printf("%d\n",ans);

	return 0;
}
