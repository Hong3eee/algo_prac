import java.util.Scanner;

public class Main {
	int n , k ;
	int dp[][];
	Main(){
		
		Scanner  in  = new Scanner(System.in);
		n =  in.nextInt();
		k =  in.nextInt();
		dp = new int  [k+5][n+5];
		for(int i =0; i <=n;i++){
			dp[1][i]=1;
		}
		for(int i = 2;i<=k;i++){
			for(int j = 0;j<=n;j++)
				for(int l = 0;l<=j;l++){
					dp[i][j] =(dp[i][j]+dp[i-1][j-l])%1000000000;
				}
		}
		System.out.println(dp[k][n]);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

