import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	int  t,n,m,map[][],cnt=0;
	int dx[]={0,-1,0,1},newx,newy,k_list[];
	int dy[]={-1,0,1,0};
	boolean  visited [][];
	ArrayList<Integer> k;
	ArrayList<node> list;
	Queue<node> q;
	Main(){
		Scanner sc = new Scanner(System.in);
		int t= sc.nextInt();
		for(int o = 0 ;o <t;o++){
			n =  sc.nextInt();
			m = sc.nextInt();
			map =  new int [n+1][m+1];
			k_list = new int[30];
			k = new ArrayList<Integer>();
			q= new LinkedList();
			list = new ArrayList<node>();
			visited = new boolean  [n+1] [m+1];
			String a;
			for(int  i =1 ; i < n +1; i++){
				a =  sc.next();
				for(int j = 1; j<m+1;j++){
					if(a.charAt(j-1)=='*')
						map[i][j] =-1;
					else if(a.charAt(j-1)=='.')
						map[i][j] = 0;
					else
						map[i][j] = a.charAt(j-1);
				}
			}
			a = sc.next();
			if(a.charAt(0)!='0')
				for(int i = 0 ; i <a.length(); i++){
					k.add((int)a.charAt(i));
					k_list[(int)a.charAt(i)-96]++;
				}
			for(int i = 1; i <n +1;i++){
				if(map[i][1]>=0)
					q.add(new node(i,1));
				if(map[i][m]>=0)
					q.add(new node(i,m));
			}
			for(int i = 2; i <m +1;i++){
				if(map[1][i]>=0)
					q.add(new node(1,i));
				if(map[n][i]>=0)
					q.add(new node(n,i));
				
			}
			search();
			int l = 0;
			while(l<list.size()){
				for(int i = 0 ; i <list.size();i++){
					node tmp =list.get(i);
					if(!visited[tmp.i][tmp.j]){
						for(int j =0;j<k.size();j++ )
							if(map[tmp.i][tmp.j]==(k.get(j)-32)){
								q.add(new node(tmp.i,tmp.j));
							}
					}
				}
				search();
				l++;
			}
			System.out.println(cnt);
			cnt=0;
		}
	}
	public void search(){
		while(!q.isEmpty()){
			node tmp =  q.poll();
			boolean check =  true;
			int k_size =  k.size();
			if(visited[tmp.i][tmp.j])
				continue;
			if(map[tmp.i][tmp.j]==36)
				cnt++;
			if(map[tmp.i][tmp.j]>=65&&map[tmp.i][tmp.j]<=90){
				check=false;
				for(int i = 0 ; i <k_size;i++){
					if(map[tmp.i][tmp.j]==(k.get(i)-32)){		
						check =true;
						break;
					}
				}
			}
			if(!check){
				list.add(new node(tmp.i,tmp.j));
				continue;
			}

			visited[tmp.i][tmp.j]=true;
			if(map[tmp.i][tmp.j]>=97&&map[tmp.i][tmp.j]<=122&&k_list[map[tmp.i][tmp.j]-96]==0){
				k.add(map[tmp.i][tmp.j]);
				k_list[map[tmp.i][tmp.j]-96]++;
			}
			for(int i =  0 ; i <4; i ++)
			{
				newy = tmp.i+dy[i];
				newx = tmp.j+dx[i];
				if(newy>0&&newy<=n&&newx>0&&newx<=m&&!visited[newy][newx]&&(map[newy][newx]>=0))
					q.add(new node(newy,newx));
			}
		}
	}
	class node {
		int i ,  j;
		node(int i , int  j ){
			this.i = i;
			this.j = j;
		}

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

