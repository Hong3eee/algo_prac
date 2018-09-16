import java.util.PriorityQueue;
import java.util.Scanner;
public class Main {
	int n,m,map[][],min=-1;
	PriorityQueue<r> q;
	int di[] = {0,1,0,-1};
	int dj[] = {1,0,-1,0};
	boolean  visited[][];
	Main(){
		Scanner in = new Scanner (System.in);
		m =  in.nextInt();
		n = in.nextInt();
		map = new int[n+1][m+1];
		visited = new boolean [n+1][m+1];
		q=  new PriorityQueue();
		String a;
		for(int i = 1; i <n+1;i++) {
			a = in.next();
			for(int j = 0; j <m;j++) 			
				map[i][j+1] = a.charAt(j)-48;
		}
		q.add(new r(1,1,0));
		while(!q.isEmpty()) {
			r  tmp = q.poll();
			if(map[tmp.i][tmp.j]==1)
				tmp.cnt+=1;
			if(tmp.i==n&&tmp.j==m) {
				min =tmp.cnt;
				break;
			}
			visited[tmp.i][tmp.j]=true;
			int newi,newj;
			for(int i = 0 ; i <4; i ++) {
				newi = tmp.i+di[i];
				newj = tmp.j+dj[i];
				if(newi>0&&newi<n+1&&newj>0&&newj<m+1)
					if(!visited[newi][newj])
						q.add(new r(newi,newj,tmp.cnt));
			}
		}
		System.out.println(min);
	}
	class r implements Comparable<r>{
		int i,j,cnt;
		r(int i ,int j , int cnt){
			this.i = i;
			this.j = j;
			this.cnt = cnt;
		}
		@Override
		public int compareTo(r arg0) {
			// TODO Auto-generated method stub
			if(this.cnt<arg0.cnt)
				return -1;
			return 1;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}

