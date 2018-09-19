import java.util.Scanner;

public class Main {
	int  n , m ,x,y ,k,map[][],dice[];
	Main(){
		Scanner in  = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		y = in.nextInt();
		x = in.nextInt();
		k = in.nextInt();
		dice= new int[7];
		map = new int[n+1][m+1];
		for(int i = 0; i <n;i++)
			for(int j = 0; j <m;j++)
				map[i][j] =in.nextInt();
		for(int i = 1; i <k+1;i++) {
			int d =in.nextInt();
			move(d);
		}
	}
	public void move(int d) {
		int tmp;
		switch(d) {
		case 1 :
			if(x+1>=m)
				return;
			x+=1;
			tmp =dice[6];
			dice[6] =dice[3];
			dice[3] =dice[1];
			dice[1] =dice[4];
			dice[4]= tmp;
			break;
		case 2 :
			if(x-1<0)
				return;
			x-=1;
			tmp = dice[6];
			dice[6] =dice[4];
			dice[4] =dice[1];
			dice[1] =dice[3];
			dice[3] =tmp;
			break;
		case 3 :
			if(y-1<0)
				return;
			y-=1;
			tmp = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] =tmp;
			break;
		case 4 :
			if(y+1>=n)
				return;
			y+=1;
			tmp= dice [6];
			dice[6]=dice[5];
			dice[5]=dice[1];
			dice[1]=dice[2];
			dice[2] =tmp;
			break;
		}
		if(map[y][x]==0) 
			map[y][x]=dice[6];
		else {
			dice[6] =map[y][x];
			map[y][x]=0;
		}
		System.out.println(dice[1]);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}

