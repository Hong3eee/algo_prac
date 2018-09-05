
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	int n , k ,min=-1 ;
	PriorityQueue<place> q;
	boolean visited[];
	Main(){
		Scanner in =  new Scanner(System.in);
		n = in.nextInt();
		k = in.nextInt();
		q = new PriorityQueue<place>();
		visited = new boolean[100001];
		q.add(new place(n,k-n,0));
		while(!q.isEmpty()) {
			place tmp= q.poll();
			if(tmp.x-k==0) {
				System.out.println(tmp.cnt);
				break;
			}
			if(visited[tmp.x])
				continue;
			visited[tmp.x]=true;
			if(tmp.x>k) {
				q.add(new place(k,tmp.sub-(tmp.x-k),tmp.cnt+(tmp.x-k)));
			}
			else {
				if(tmp.x-1>=0&&k>tmp.x)
					q.add(new place(tmp.x-1,k-tmp.x+1,tmp.cnt+1));
				if(tmp.x+1<=100000) 
					q.add(new place(tmp.x+1,k-tmp.x-1,tmp.cnt+1));
				if(tmp.x*2<=100000&&k>=tmp.x+tmp.x/2)
					q.add(new place(tmp.x*2,k-tmp.x*2,tmp.cnt+1));
			}
		}
	}
	class place implements Comparable<place>{
		int x;
		int cnt;
		int sub;
		place (int x,int sub,int cnt){
			this.x= x;
			this.sub= sub;
			this.cnt = cnt;
		}
		@Override
		public int compareTo(place arg0) {
			// TODO Auto-generated method stub
			if(Math.abs((int)this.cnt)<Math.abs(arg0.cnt))
				return -1;
			return 1;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}

