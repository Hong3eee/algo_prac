import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
	int t ,n,w,h,map[][],min=999,o=0;
	boolean visited[][];
	PriorityQueue <node>q ;
	Solution(){
		Scanner sc= new Scanner (System.in);
		map = new int[16][13];
		visited=  new boolean [16][13];
		t =sc.nextInt();
		while(o++<t) {
			n = sc.nextInt();
			w = sc.nextInt();
			h = sc.nextInt();
			q = new PriorityQueue();
			for(int i =0 ;  i<h;i++)
				for(int j =0 ;  j<w;j++)
					map[i][j] = sc.nextInt();
			find(map,0);
			while(!q.isEmpty()) {
				node tmp = q.poll();
				int tmps = tmp.cnt();
				
				tmp.check(tmp.i, tmp.j);
				tmp.after();
				min= (Math.min(min, tmp.cnt()));
				if(tmp.n==n-1)
					continue;				
				find(tmp.map1,tmp.n+1);
			}
			if(min<0)
				min=0;
			System.out.println("#"+o+" "+min);
			min=999;
			q.clear();
		}
	}
	public void find(int map[][],int n) {
		for(int i =0 ;  i<w;i++)
			for(int j =0 ;  j<h;j++)
			{
				if(map[j][i]!=0) {
					q.add(new node (j,i,map,n));
					break;
				}
			}
	}
	class node implements Comparable<node> {
		int i , j , map1[][],n,cnt =0;
		node(int i , int  j , int[][] maps,int n){
			this.i= i;
			this.j= j;
			map1 = new int [h][w];
			for(int l = 0; l<h;l++)
				for(int k = 0; k<w;k++)
					map1[l][k]=  maps[l][k];
			this.n= n;
		}
		public int cnt() {
			cnt=0;
			for(int l = 0; l<h;l++)
				for(int k = 0; k<w;k++)
					if(map1[l][k]!= 0)
						cnt++;
			return cnt;
		}
		public void check(int i ,int  j) {
			if(visited[i][j])
				return;
			int check =  map1[i][j];
			visited[i][j] = true;
			int newx=0,newy = 0;
			for(int k = 1 ; k<check;k++) {
				newy= i+k;
				if(newy<h&&!visited[newy][j]) 
					check(newy,j);
				newy= i-k;
				if(newy>=0&&!visited[newy][j]) 
					check(newy,j);
				newx= j+k;
				if(newx<w&&!visited[i][newx]) 
					check(i,newx);
				newx= j-k;
				if(newx>=0&&!visited[i][newx]) 
					check(i,newx);
			}
		}

		public void after() {
			for(int l = 0; l<h;l++)
				for(int k = 0; k<w;k++)
				{
					if(visited[l][k]) {
						map1[l][k]=0;
						visited[l][k] =false;
					}
				}

			for(int l = h-1; l>=0;l--)
				for(int k = 0; k<w;k++) {
					if(map1[l][k]!=0) {
						int tmp = map1[l][k];
						int newy = l+1;
						while(newy<h&&map1[newy][k]==0) {
							newy++;
						}
						map1[l][k]=0;
						map1[newy-1][k]=tmp;
					}
				}
				}
		@Override
		public int compareTo(node arg0) {
			// TODO Auto-generated method stub
			if(this.cnt<arg0.cnt)
				return -1;
			return 1;
		}

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Solution();
	}

}

