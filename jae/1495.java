import java.util.Scanner;

public class Main {
	int n,s,m,map[],dp[][],max=-1;
	Main(){
		Scanner  in  = new Scanner (System.in);
		n =  in.nextInt();
		s = in.nextInt();
		m =  in.nextInt();
		map =  new int[n+1];
		dp = new int[n+1][1001];
		for(int i = 0; i <n ;i++)
			map[i] =  in.nextInt();
		if(s-map[0]>=0)
			dp[0][s-map[0]]=1;
		if(s+map[0]<=m)
			dp[0][s+map[0]]=1;
		for(int i = 1; i<n;i++) {
			for(int j = m; j>=0;j--) {
				if(dp[i-1][j]==1)
				{
					if(j-map[i]>=0) 
						dp[i][j-map[i]]=1;
					if(j+map[i]<=m)
						dp[i][j+map[i]]=1;
				}
			}
		}
		for(int j = 1000; j>=0;j--) {
			if(dp[n-1][j]==1)
			{
				max=j;
				break;
			}
		}
		System.out.println(max);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

