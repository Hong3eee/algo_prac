import java.util.Scanner;

public class Main {
	int  n,m,map[][],tmp_map[][];
	int dy[] =  {0,-1,0,1};
	int dx[] =  {-1,0,1,0};
	int v =2;
	int max =0;
	int count [] ;
	Main(){
		Scanner in = new Scanner (System.in);
		m = in.nextInt();
		n = in.nextInt();
		map = new int[n+1][m+1];
		tmp_map = new int[n+1][m+1];
		for(int i =1; i <n+1;i++)
			for(int j =1; j <m+1;j++)
				map[i][j] = 15-in.nextInt();
		check_room();
	}
	public void check_room() {
		for(int i = 1; i <n+1; i ++)
			for(int j = 1; j <m+1; j ++)
			{
				if(tmp_map[i][j]==0) {
					paint(i,j,v++);
				}
			}

		count = new int[v];
		for(int i = 1; i <n+1; i ++) {
			for(int j = 1; j <m+1; j ++)
				count[tmp_map[i][j]]++;
		}

		for(int i = 2; i <v; i ++) 
			if(max<count[i])
				max =count[i];		
		System.out.println(v-2);
		System.out.println(max);
		check2();
	}
	public void paint(int i , int j,int v) {
		tmp_map [i][j]=v;
		int newi=0,newj=0;
		int tmp=map[i][j];
		for(int k = 3; k>=0; k--) {
			if((tmp-Math.pow(2,k))<0)
				continue;
			tmp-=Math.pow(2,k);
			newi =i+dy[k];
			newj =j+dx[k];
			if(newi>0&&newi<=n&&newj>0&&newj<=m&&tmp_map[newi][newj]==0) {
				paint(newi,newj,v);
			}
		}
	}
	public void check2() {
		boolean visited [][] = new boolean [v][v],check;
		int newi=0,newj=0;
		max =-1;
		for(int k = 2 ; k <v;k++) {
			for(int i = 1; i <n+1; i ++)
				for(int j = 1; j <m+1; j ++)
				{
					if(tmp_map[i][j]!=k&&!visited[k][tmp_map[i][j]]) {
						check=false;
						for(int x =0 ; x<4;x++) {
							newi =i+dy[x];
							newj =j+dx[x];
							if(newi>0&&newi<=n&&newj>0&&newj<=m&&tmp_map[newi][newj]==k) {
								check=true;
								break;
							}
						}
						if(check) {
							visited [k][tmp_map[i][j]] =true;
							visited [tmp_map[i][j]][k] =true;
							int tmp = count[k]+count[tmp_map[i][j]];
							if(tmp>max)
								max = tmp;
						}
					}
				}
		}
		System.out.println(max);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}
