import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	int  n ,x,y,d,g ,map[][];
	int dx[] = {1,0,-1,0};
	int dy[]= {0,-1,0,1};
	int sx,sy;
	int count=0;
	ArrayList <cases> list ;
	Main(){
		Scanner  in =  new Scanner(System.in);
		n= in.nextInt();
		list = new ArrayList<cases>();
		map=new int [101][101];
		for(int i = 1 ; i <=n ; i++)
		{
			list.clear();
			x = in.nextInt();
			y = in.nextInt();
			d = in.nextInt();
			list.add(new cases(x,y));
			map[x][y]=i;
			sx =x+dx[d];
			sy =y+dy[d];
			map[sx][sy]=i;
			list.add(new cases(sx,sy));
			g = in.nextInt();
			while(g-->0) {
				draw(i);
			}
		}
		check();
	}
	public void draw(int i) {
		int size = list.size();
		int ax,ay;
		for(int k = 0;k<size;k++) {
			ax = sx+sy-list.get(k).y;
			ay = sy-sx+list.get(k).x;
			if(map[ax][ay]==i)
				continue;
			map[ax][ay] =i;
			list.add(new cases(ax,ay));
		}
		ax = -sx+x;
		ay = -y+sy;
		sx =sx+ay;
		sy = sy+ax;
	}
	public void check() {
		for(int i = 0 ; i <100;i++) {
			for(int j   = 0 ; j <100;j++) {
				if(map[i][j]!=0&&map[i+1][j]!=0&&map[i][j+1]!=0&&map[i+1][j+1]!=0) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
	class cases {
		int x,y;
		cases(int x,int y){
			this.x =x;
			this.y = y;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main() ;
	}

}

