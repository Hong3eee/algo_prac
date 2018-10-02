import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	int n,  map[][],res[],res2[],max1=-1,max2=-1;
	ArrayList<node> list;
	ArrayList<node> list2;
	boolean visited[],visited2[];
	Main(){
		Scanner sc= new Scanner(System.in);
		n = sc.nextInt();
		map=  new int[n+1][n+1];
		list = new ArrayList();
		list2 = new ArrayList();
		for(int i  =1;  i <=n ; i++)
			for(int j  =1;  j <=n ; j++) {
				map[i][j] =sc.nextInt();
				if(i%2 ==0) {
					if(j%2==1&&map[i][j] ==1)
						list.add(new node(i,j));
					else if(j%2==0&&map[i][j] ==1)
						list2.add(new node(i,j));
				}
				if(i%2 ==1) {
					if(j%2==0&&map[i][j] ==1)
						list.add(new node(i,j));
					else if(j%2==1&&map[i][j] ==1)
						list2.add(new node(i,j));
				}
			}
		res =new int[list.size()+1];
		res2 =new int[list2.size()+1];
		visited = new boolean[list.size()+1];
		visited2 = new boolean[list2.size()+1];
		dfs(list,0,1,res,visited);
		dfs(list2,0,2,res2,visited2);
		System.out.println(max1+max2);
	}
	public void dfs(ArrayList<node> list,int i,int f,int res[],boolean visited[]) {
		if(i>=list.size()) {
			int cnt= 0;
			for(int j  =0;  j <list.size() ; j++) {
				if(res[j]==1)
					cnt++;
			}
			//	System.out.println(cnt);
			if(f==1)
				max1 =Math.max(cnt, max1);
			else
				max2 =Math.max(cnt, max2);
			return;
		}
		boolean check=false;
		for(int j =0;j<i;j++) {
			if(res[j]==1&&Math.abs(list.get(j).i-list.get(i).i)==Math.abs(list.get(j).j-list.get(i).j))
			{
				check=true;
				break;
			}
		}
		if(!check)
		{
			res[i]=1;
			visited[i]=true;
			dfs(list,i+1,f,res,visited);
		}
		res[i]=0;
		visited[i]=true;
		dfs(list,i+1,f,res,visited);
		visited[i]=false;

	}
	class node {
		int i , j;
		node(int i , int j){
			this.i = i;
			this.j = j;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

