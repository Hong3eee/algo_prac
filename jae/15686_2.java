import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	int n,m,map[][],sum=-1;
	int res[],store_cnt=0;
	ArrayList<h> h_list;
	ArrayList<s> s_list;
	Main(){
		Scanner  in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		map = new int[n+1][n+1];
		h_list =  new ArrayList<h>();
		s_list = new ArrayList<s>();
		for(int i=1; i <n+1;i++)
			for(int j=1; j <n+1;j++) {
				map[i][j] =in.nextInt();
				if(map[i][j] == 1)
					h_list.add(new h(i,j));
				if(map[i][j]==2) {
					store_cnt++;
					s_list.add(new s(i,j));
				}
			}
		res = new int[store_cnt+1];
		dfs(0,0);
		System.out.println(sum);
	}
	public void dfs(int  i ,int cnt) {
		if(cnt<=m&&i==store_cnt)
		{
			int sums=0;
			int min=-1;
			for(int k = 0; k<h_list.size();k++) {
				min= -1;
				for(int j=0;j<store_cnt;j++) {
					if(res[j]==1) {
						int tmp_i = s_list.get(j).i-h_list.get(k).i;
						if(tmp_i<0)
							tmp_i*=-1;
						int tmp_j = s_list.get(j).j-h_list.get(k).j;
						if(tmp_j<0)
							tmp_j*=-1;
						int tmp =  tmp_i+tmp_j;
						if(min<0||tmp<min)
							min = tmp;
					}
				}
				if(min<0)
					return;
				sums+=min;
			}
			if(sum<0||sums<sum)
				sum =sums;	
			return;
		}
		res[i]=0;
		dfs(i+1,cnt);
		res[i]=1;
		dfs(i+1,cnt+1);
	}
	class h{
		int i,j;
		h(int i,int j ){
			this.i=i;
			this.j = j;
		}
	}	
	class s{
		int i,j;
		s(int i,int j ){
			this.i=i;
			this.j = j;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}

