import java.util.PriorityQueue;
import java.util.Scanner;
public class Main {
	int  n;
	PriorityQueue<mem> q;
	int map[],res[];
	boolean check;
	Main(){
		Scanner in = new Scanner(System.in);
		map =new int[10];
		res = new int[10];
		q= new PriorityQueue<mem>();
		for(int i = 0; i <9 ;i++) {
			n =  in.nextInt();
			q.add(new mem(n));
		}
		for(int i = 0 ; i <9;i++) {
			map[i] =  q.poll().n;
		}
		dfs(0,0,0);
	}
	public void dfs(int idx, int cnt,int sum) {
		if(!check) {
			if(idx==9||cnt==7) {
				if(cnt==7&&sum==100) {
					for(int i = 0 ; i <9;i++) 
						if(res[i]==1)
							System.out.println(map[i]);
					check=true;
				}
				return;
			}
			res[idx] =1;
			dfs(idx+1,cnt+1,sum+map[idx]);
			res[idx] = 0;
			dfs(idx+1,cnt,sum);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
	class mem implements Comparable<mem>{
		int n;
		mem(int n ){
			this.n = n;
		}
		@Override
		public int compareTo(mem arg0) {
			// TODO Auto-generated method stub
			if(this.n<arg0.n)
				return -1;
			return 1;
		}	
	}
}

