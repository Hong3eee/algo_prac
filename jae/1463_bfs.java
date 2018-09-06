import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	Queue<input> q;
	int n;
	boolean visited[];
	Main(){
		Scanner  in =  new Scanner(System.in);
		n = in.nextInt();
		q=  new LinkedList<input>();
		visited = new boolean[1000001];
		q.add(new input(n,0));
		while(!q.isEmpty()) {
			input  i =  q.poll();
			int x =i.n;
			int num =i.num;
			if(x == 1) {
				System.out.println(num);
				return;
			}
			if(!visited[x-1]) {
				q.add(new input(x-1,num+1));
			}
			if(!visited[x/2]&&x%2==0) {
				q.add(new input(x/2,num+1));
			}
			if(!visited[x/3]&&x%3==0) {
				q.add(new input(x/3,num+1));
			}
			visited[x] =true;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

	class input{
		int n ;
		int num;
		input (int n,int num){
			this.n = n;
			this.num = num;
		}
	}
}

