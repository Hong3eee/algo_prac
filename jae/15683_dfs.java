import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
public class Main {
	int n,m,map[][],min=-1;
	ArrayList<cam> list;
	Main(){
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m =  in.nextInt();
		list = new ArrayList<cam>();
		map = new int[n+1][m+1];
		for(int i = 1; i < n+1; i ++)
			for(int j = 1; j < m+1; j ++) {
				map[i][j] =in.nextInt();
				if(map[i][j]!=0&&map[i][j]!=6)
					list.add(new cam(i,j,map[i][j]));
			}
		dfs(0,map);
		System.out.println(min);
	}
	public void dfs(int  num,int tmp_map[][]) {
		if(num==list.size()) {
			int cnt = 0;
			for(int i = 1; i < n+1; i ++)
				for(int j = 1; j < m+1; j ++) {
					if(tmp_map[i][j]==0)
						cnt++;
				}
			if(min==-1||min>cnt)
				min =cnt;
			return;	
		}
		int maps[][]= new int[n+1][m+1];
		cam tmp =  list.get(num);
		switch(tmp.t){
		case 1:
			for(int i =0;i <4; i ++) {
				copy_array(maps,tmp_map);
				check(tmp.i,tmp.j,i,maps);
				dfs(num+1,maps);
			}
			break;
		case 2:
			for(int i =0;i<2; i++) {
				copy_array(maps,tmp_map);
				check(tmp.i,tmp.j,i,maps);
				check(tmp.i,tmp.j,i+2,maps);
				dfs(num+1,maps);	
			}
			break;
		case 3:
			for(int i =0;i <4; i ++) {
				copy_array(maps,tmp_map);
				check(tmp.i,tmp.j,(i)%4,maps);
				check(tmp.i,tmp.j,(i+1)%4,maps);
				dfs(num+1,maps);
			}
			break;
		case 4:
			for(int i =0;i <4; i ++) {
				copy_array(maps,tmp_map);
				check(tmp.i,tmp.j,(i)%4,maps);
				check(tmp.i,tmp.j,(i+1)%4,maps);
				check(tmp.i,tmp.j,(i+2)%4,maps);
				dfs(num+1,maps);
			}
			break;
		case 5:
			copy_array(maps,tmp_map);
			check(tmp.i,tmp.j,0,maps);
			check(tmp.i,tmp.j,1,maps);
			check(tmp.i,tmp.j,2,maps);
			check(tmp.i,tmp.j,3,maps);
			dfs(num+1,maps);
			break;
		}
	}
	public void copy_array(int maps[][],int copy_map[][]) {
		for(int i =1;i<n+1;i++)
			for(int j =1;j<m+1;j++)
				maps[i][j]=copy_map[i][j];
		
	}
	public void check(int i , int j , int d,int maps[][]) {
		switch(d) {
		case 0:
			for(int k = j;k<m+1;k++) {
				if(maps[i][k]==6)
					break;
				maps[i][k]= -1;
			}
			break;
		case 1:
			for(int k = i;k<n+1;k++)
			{
				if(maps[k][j]==6)
					break;
				maps[k][j]= -1;
			}
			break;
		case 2:
			for(int k = j;k>0;k--) {
				if(maps[i][k]==6)
					break;
				maps[i][k]= -1;	
			}
			break;
		case 3:
			for(int k = i;k>0;k--) {
				if(maps[k][j]==6)	
					break;
				maps[k][j]= -1;
			}
			break;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
	class cam{
		int i,j,t;
		cam (int i,int j , int t){
			this.i = i ;
			this.j = j ;
			this.t = t ;
		}
	}
}

