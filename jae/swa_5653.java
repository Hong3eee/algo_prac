import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
	int  n, m , k;
	int dx[]= {0,1,0,-1},t;
	int dy[] = {1,0,-1,0};
	boolean visited[][];
	ArrayList<node> list;
	Solution(){
		Scanner sc= new Scanner (System.in);
		list= new ArrayList();
		t= sc.nextInt();
		for(int p = 0 ; p<t; p++) {
			visited = new boolean[500][500];
			n = sc.nextInt();
			m = sc.nextInt();
			k = sc.nextInt();

			for(int i = 0 ; i < n ; i ++)
				for(int j = 0 ; j < m ; j ++) {	
					int v  = sc.nextInt();
					if(v!=0) {
						list.add(new node(i,j,v,1));
						visited[i+250][j+250] =true;
					}
				}
			for(int l = 0; l <k;l++) {

				int size= list.size();
				for(int i = 0 ; i <size;i++) {
					list.get(i).act--;
					if(list.get(i).s==1&&list.get(i).act<=0) {
						list.get(i).s=2;
						list.get(i).act=list.get(i).n;
					}
					else if(list.get(i).s==2&&list.get(i).act>0) { 
						if(list.get(i).act+1==list.get(i).n)
							for(int h = 0 ; h<4;h++) {
								int newy=  list.get(i).i+dy[h];
								int newx=  list.get(i).j+dx[h];
								boolean check =false;
								if(!visited[250+newy][250+newx]) {
									list.add(new node(newy,newx,list.get(i).n,1));
									visited[250+newy][250+newx]=true;
								}
							}
					}
					else if(list.get(i).s==2&&list.get(i).act<=0) { 
						if(list.get(i).n==1)
							for(int h = 0 ; h<4;h++) {
								int newy=  list.get(i).i+dy[h];
								int newx=  list.get(i).j+dx[h];
								boolean check =false;
								if(!visited[250+newy][250+newx]) {
									list.add(new node(newy,newx,list.get(i).n,1));
									visited[250+newy][250+newx]=true;
								}

							}
						list.get(i).s=3;
					}
				}
			}
			int cnt= 0;
			for(int i = 0 ; i <list.size();i++) {
				if(list.get(i).s==1||list.get(i).s==2)
					cnt++;
			}
			System.out.println("#"+(p+1)+" "+cnt);
			list.clear();
		}
	}
	class node{
		int i,j,s,n,act;
		node(int i ,int  j , int n , int s){
			this.i = i ;
			this.j = j ;
			this.n  = n ;
			this.s = s ;
			this.act =n;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new  Solution();
	}
}

