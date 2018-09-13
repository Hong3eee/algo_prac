
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class Main {
	int t;
	int a,b;
	Queue<node> q ;
	int visited[];
	char p[];
	Main(){
		Scanner in = new Scanner (System.in);
		t=  in.nextInt();
		for(int i = 0 ; i <t; i++) {
			p = new char[100001];
			visited = new int [10001];
			q = new  LinkedList();
			a = in.nextInt();
			b = in.nextInt();
			visited[a]=a;
			q.add(new node(a,""));
			bfs();
			int tmp =b;
			q.clear();
		}
	}
	public void bfs() {
		while(!q.isEmpty()) {
			node tmp = q.poll();
			if(tmp.v==b) {
				System.out.println(tmp.str);
				return;
			}
			else {
				int dou = d(tmp.v);
				int sub = s(tmp.v);
				int right =r(tmp.v);
				int left =l(tmp.v);
				if(visited[dou]==0) {
					q.add(new node(dou,tmp.str+'D'));
					visited[dou]=tmp.v;
					p[dou]='D';
				}
				if(visited[sub]==0) {
					q.add(new node(sub,tmp.str+'S'));
					visited[sub]=tmp.v;
					p[sub]='S';
				}
				if(visited[left]==0) {
					q.add(new node(left,tmp.str+'L'));
					visited[left]=tmp.v;
					p[left]='L';

				}
				if(visited[right]==0) {
					q.add(new node(right,tmp.str+'R'));
					visited[right]=tmp.v;
					p[right]='R';		
				}
			}
		}
	}
	public int d(int  i ) {
		return (i*2)%10000;
	}
	public int s(int  i ) {
		if (i==0)
			return 9999;
		return (i-1);
	}
	public int r(int i) {
		int tmp = i%10;
		i= tmp*1000+i/10;
		return i;
	}
	public int l(int i) {
		int tmp = i/1000;
		i = (i%1000)*10+tmp;
		return i;
	}
	class node{
		int v;
		String str;
		node(int v, String str){
			this.v =v;
			this.str = str;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

