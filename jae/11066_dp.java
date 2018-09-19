import java.util.Scanner;
public class Main {
	int t;
	int n;
	int map[][];
	Main(){
		Scanner in =  new Scanner(System.in);
		t =  in.nextInt();
		for(int u=0;u<t;u++) {
			n = in.nextInt();
			map = new int[n+1][n+1];
			for(int i =1; i <n+1;i++) 
				map[0][i]= in.nextInt();
			for(int i =1; i <n;i++) 
				map[i][i+1] = map[0][i]+map[0][i+1];
			int  i =1,j=3, m=2;
			while(true) {
				int tmp_sum=0;
				for(int k = i;k<=j;k++) 
					tmp_sum +=map[0][k];
				for(int k = i;k<j;k++) {
					int tmp=0;
					tmp+= map[i][k]+map[k+1][j]+map[n][j]+tmp_sum;
					if(map[i][j]==0||map[i][j]>tmp)
						map[i][j]=tmp;
				}
				if(i==1&&j==n) 
					break;
				if(i+1>n||j+1>n)
				{
					m++;
					i=1;
					j=i+m;				
				}
				else
				{
					i++;
					j++;
				}
			}
			System.out.println(map[1][n]);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

