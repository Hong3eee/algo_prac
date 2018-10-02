import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	int res[];
	int cnt=0;
	boolean visited[],find;
	ArrayList<node>list;
	Main(){
		res = new int[13];
		visited = new boolean[13];
		Scanner sc = new Scanner(System.in);
		String a;
		list = new ArrayList();
		for(int i =1; i <=5;i++) {
			a = sc.next();
			for(int j =1; j <=9;j++)
			{
				char c = a.charAt(j-1);
				if(c=='x') {
					cnt++;
					list.add(new node(i,j));
				}
				else if(c!='.') {
					res[cnt++]=c-64;
					list.add(new node(i,j));
					visited[c-64]=true;
				}
			}
		}
		dfs(0);
	}
	public void dfs(int i) {
		if(!find) {
			if(res[0]+res[2]+res[5]+res[7]>26)
				return;
			if(res[1]+res[2]+res[3]+res[4]>26)
				return;
			if(res[0]+res[3]+res[6]+res[10]>26)
				return;
			if(res[7]+res[8]+res[9]+res[10]>26)
				return;
			if(res[4]+res[6]+res[9]+res[11]>26)
				return;
			if(res[1]+res[5]+res[8]+res[11]>26)
				return;
			if(i>=cnt) {
				int cnts= 0;
				for(int j =1;j<=5;j++) {
					for(int k =1;k<=9;k++) {
						if(cnts<cnt&&list.get(cnts).i==j&&list.get(cnts).j==k) 
							System.out.print((char)(res[cnts++]+64));
						else System.out.print('.');
					}
					System.out.println();
				}
				find =true;
				return;
			}
			int s=0;
			boolean check=false;
			if(i>=5) {
				for(int j=1;j<=4;j++) {
					if(res[j]==0) {
						check=true;
						break;
					}
					else
						s+=res[j];
				}
				if(!check&&s!=26)
					return;
			}
			if(i>=8) {
				s=0;
				check=false;
				if(res[0]==0||res[2]==0||res[5]==0||res[7]==0)
					check=true;
				s = res[0]+res[2]+res[5]+res[7];
				if(!check&&s!=26)
					return;
			}
			if(i>=11) {
				s=0;
				check=false;
				for(int j=7;j<=10;j++) {
					if(res[j]==0) {
						check=true;
						break;
					}
					else
						s+=res[j];
				}	
				if(!check&&s!=26)
					return;
				s=0;
				check=false;
				if(res[0]==0||res[3]==0||res[6]==0||res[10]==0)
					check=true;
				s = res[0]+res[3]+res[6]+res[10];
				if(!check&&s!=26)
					return;
				if(i>=11) {
					s=0;
					check=false;
					if(res[1]==0||res[5]==0||res[8]==0||res[11]==0)
						check=true;
					s = res[1]+res[5]+res[8]+res[11];
					if(!check&&s!=26)
						return;
					s=0;
					check=false;
					if(res[4]==0||res[6]==0||res[9]==0||res[11]==0)
						check=true;
					s = res[4]+res[6]+res[9]+res[11];
					if(!check&&s!=26)
						return;
				}
			}
			if(res[i]==0)
				for(int j=1; j <=12;j++) {
					if(!visited[j]) {
						visited[j]=true;
						res[i]=j;
						dfs(i+1);
						res[i]=0;
						visited[j]=false;
					}
				}
			else
				dfs(i+1);
		}
	}
	class node{
		int i,j;
		node(int i ,int j){
			this.i =i;
			this.j =j;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}
