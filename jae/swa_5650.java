import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class Solution {
	int  t,n,map[][];
	int max =-1;
	boolean visited[][][];
	int dy [] = {-1,0,1,0};
	int dx [] = {0,1,0,-1};
	Queue<node>q;
	Queue<node>q2;
	Solution(){
		Scanner sc = new Scanner (System.in);
		t=  sc.nextInt();
		for(int k=1;k<=t;k++) {
			n = sc.nextInt();
			map = new int[n][n];
			visited =  new boolean [4][n][n];
			q=  new LinkedList();
			q2=  new LinkedList();
			for(int i  = 0 ; i <n ; i ++)
				for(int j  = 0 ; j <n ; j ++){
					map[i][j]=sc.nextInt();
					if(map[i][j]==0)
						q.add(new node(i, j,0));
				}
			while(!q.isEmpty()){
				node tmp =  q.poll();
				for(int i  =0; i <4; i++)
				{
					tmp.d=i;
					q2.add(tmp);
					dfs(tmp.i,tmp.j);
					init();
				}
			}
			System.out.println("#"+k+" "+max);
			max =0;
			q.clear();
			q2.clear();
		}
	}
	public void init(){
		for(int k =0;k<4;k++)
			for(int i  = 0 ; i <n ; i ++)
				for(int j  = 0 ; j <n ; j ++)
					visited[k][i][j]=false;
	}
	public void dfs(int sr, int sc){
		boolean check=false;
		while(!q2.isEmpty()){
			node tmp =  q2.poll();
			int i = tmp.i;
			int j = tmp.j;
			int p = tmp.p;
			int d= tmp.d;
			if((sr==i&&sc ==j&&tmp.cnt!=0)||map[i][j]==-1){
				max =Math.max(p, max);
				return;
			}
			if(visited[d][i][j])
				return;
			visited[d][i][j]=true;
			int newy = i;
			int newx = j;
			if(map[i][j]==0) 
			{
				newy = i+dy[d];
				newx = j+dx[d];
				if(newy>=n||newy<0||newx<0||newx>=n)
				{
					p++;
					newy=i;
					newx=j;
					d =(d+2)%4;
				}
			}
			else if(map[i][j]>=1&&map[i][j]<=5) {
				d = dir(d,map[i][j]);
				newy = i+dy[d];
				newx = j+dx[d];
				if(newy>=n||newy<0||newx<0||newx>=n)
				{
					p++;
					newy=i;
					newx=j;
					d =(d+2)%4;
				}
				p++;
			}
			else if(map[i][j]>=6&&map[i][j]<=10&&!check) {
				int res[] =hall(i,j);
				newy =res[0];
				newx =res[1];
				check=true;
			}
			else if(map[i][j]>=6&&map[i][j]<=10&&check) {
				check= false;
				newy = i+dy[d];
				newx = j+dx[d];
				if(newy>=n||newy<0||newx<0||newx>=n)
				{
					newy=i;
					newx=j;
					d =(d+2)%4;
					p++;
				}
			}
			if(map[newy][newx]==-1)
			{
				max =Math.max(p, max);
				return;
			}
		//System.out.println(newy+" "+ newx+" "+d+" "+p);
			if(!visited[d][newy][newx]) {
				q2.add(new node(newy,newx,d,p,tmp.cnt+1));
			}
		}
	}
	public int dir(int d,int t) {
		switch(d) {
		case 0:
			switch(t){
			case 1:
				d=2;
				break;
			case 2:
				d=1;   
				break;
			case 3:
				d=3;
				break;
			case 4:
				d=2;
				break;
			case 5:
				d=2;
				break;
			}
			break;
		case 1:
			switch(t){
			case 1:
				d=3;
				break;
			case 2:
				d=3;
				break;
			case 3:
				d=2;
				break;
			case 4:
				d=0;
				break;
			case 5:
				d=3;
				break;
			}   
			break;
		case 2:
			switch(t){
			case 1:
				d=1;
				break;
			case 2:
				d=0;
				break;
			case 3:
				d=0;
				break;
			case 4:
				d=3;
				break;
			case 5:
				d=0;
				break;
			}
			break;
		case 3:
			switch(t){
			case 1:
				d=0;
				break;
			case 2:
				d=2   ;
				break;
			case 3:
				d=1;
				break;
			case 4:
				d=1;
				break;
			case 5:
				d=1;
				break;
			}
			break;
		}
		return d;

	}
	public int [] hall(int i ,int j ){
		int res[] = {0,0};
		for(int k  = 0 ; k <n ; k ++)
			for(int l = 0 ; l <n ; l ++){
				{
					if(i!=k&&j!=l&&map[i][j]==map[k][l])
					{
						res[0] =k;
						res[1] =l;
					}
				}
			}
		return res;
	}
	class node{
		int i,j ,d,p,cnt;
		node (int i , int j , int  d){
			this.i= i ;
			this.j = j;
			this.d = d;
			this.cnt= 0;
		}
		node (int i , int j , int  d, int  p,int cnt){
			this.i= i ;
			this.j = j;
			this.d = d;
			this.cnt=cnt;
			this.p = p;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Solution();
	}
}
