#include<iostream>
#include<cstdio>
using namespace std;

int dir[5] = {0,0,0,0,0};
int gear[5][8];
int pos[5][2]={{0,0},{6,2},{6,2},{6,2},{6,2}};
int K;

int main(void)
{	
	int gear_num;
	int direction;
	for(int i=1; i<5; i++)
		for(int j=0; j<8; j++)
			scanf("%1d", &gear[i][j]);

	cin >> K;
	
	while(K--)
	{	
		for(int i=1; i<5; i++)
			dir[i] = 0;

		cin >> gear_num >> direction;
		int num = gear_num;
		int num2 = gear_num-1;
		
		int temp = direction;
		int temp2 = direction;
		
		dir[num++] = -direction;
		
		for(int i=gear_num; i<4; i++)
		{
			if(gear[i][pos[i][1]]==gear[i+1][pos[i+1][0]])
				break;
			dir[num++] = temp;
			temp = -temp;
		}
		
		for(int i=gear_num; i>1; i--)
		{
			if(gear[i][pos[i][0]] == gear[i-1][pos[i-1][1]])
				break;
			dir[num2--] = temp2;
			temp2 = -temp2;
		}
		
		for(int i=1; i<5; i++)
		{	
			if(dir[i] == -1)
				dir[i] = 7;

			pos[i][0] = (pos[i][0] + dir[i]) % 8;
			pos[i][1] = (pos[i][1] + dir[i]) % 8;
		}

	}
	int total = 0;
	int temp = 1;
	for(int i=1; i<5; i++)
	{	
		if(gear[i][(pos[i][0]+2) % 8] == 1)
			total += temp;
		
		temp=temp*2;
	}
	cout << total<< endl;
}
