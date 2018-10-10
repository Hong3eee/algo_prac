import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
	int m,a,map[],t ;
	int user[][];
	int user_[][];
	int res[][];
	int dx[]={0,0,1,0,-1};
	int dy[]={0,-1,0,1,0}; 
	int lists[];
	int max= 0;
	int sum =0;
	ArrayList<charge_node> list;
	ArrayList<Integer> user_list[];
	Solution(){
		Scanner sc= new Scanner (System.in);
		t =sc.nextInt();
		for(int k = 0 ;k<t; k++){
			m = sc.nextInt();
			a = sc.nextInt();
			user = new int[2][m+1];
			user_ = new int[2][3];
			user_list =  new ArrayList[2];
			for(int i = 0 ; i <2; i ++)
				user_list[i]=new ArrayList();
			user_[0][0] = 1;
			user_[0][1] = 1;
			user_[1][0] = 10;
			user_[1][1] = 10;
			res = new int[2][m];
			map = new int[m+1];
			list = new ArrayList();
			for(int i = 0 ; i <m;i++){
				user[0][i] = sc.nextInt();
			}
			for(int i = 0 ; i <m;i++){
				user[1][i] = sc.nextInt();
			}
			for(int i = 0 ; i <a ; i ++){
				int x  = sc.nextInt();
				int y =  sc.nextInt();
				int v =  sc.nextInt();
				int p  = sc.nextInt();
				list.add(new charge_node(y,x,v,p));
			}
			lists = new int[2];

			for(int i  = 0 ; i  <m;i++){
				check(i);
				move(0,i);
				move(1,i);	
			}
			check(20);
			System.out.println("#"+(k+1)+" "+sum);
			sum= 0;
			list.clear();
		}

	}
	public void move(int u,int c){
		switch(user[u][c]){
		case 0:
			break;
		case 1:
			user_[u][0]+=dy[1];
			user_[u][1]+=dx[1];
			break;
		case 2:
			user_[u][0]+=dy[2];
			user_[u][1]+=dx[2];

			break;
		case 3:
			user_[u][0]+=dy[3];
			user_[u][1]+=dx[3];
			break;
		case 4:
			user_[u][0]+=dy[4];
			user_[u][1]+=dx[4];
			break;
		}
	}
	public void check (int n){
		for(int i = 0 ; i <2; i++)
			user_list[i].clear();
		for(int i =0 ; i <list.size();i++){
			for(int j =0 ; j <2;j++){
				if(Math.abs(user_[j][0]-list.get(i).i)+Math.abs(user_[j][1]-list.get(i).j)<=list.get(i).n)
					user_list[j].add(i);
			}
		}
		dfs(0);
		sum+=max;
		max = 0;
	}
	public void dfs(int  i ){
		if(i>1){
			int tmp = 0;
			if(lists[0]!=-1)
				tmp +=list.get(lists[0]).p;
			if(lists[1]!=-1)
				tmp +=list.get(lists[1]).p;
			if(lists[1]==lists[0]&&lists[0]!=-1)
				tmp/=2;
			max =Math.max(max,tmp);
			return;
		}
		for(int j = 0 ; j<user_list[i].size();j++){
			lists[i] =user_list[i].get(j);
			dfs(i+1);
		}
		lists[i] =-1;
		dfs(i+1);
	}

	class charge_node{
		int i , j , n ,p;
		charge_node(int i , int  j ,int  n,int p){
			this.i = i;
			this.j = j;
			this.n = n;
			this.p = p;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Solution();
	}

}

