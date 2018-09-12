import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	int  n ,count=0;
	int map[][];
	boolean check[];
	PriorityQueue<chess>q ;
	Main(){
		Scanner  in  = new Scanner (System.in);
		q=  new PriorityQueue<chess>();
		n =  in.nextInt();
		map=  new int[n+1][n+1];
		check = new boolean[n+1];
		for(int  i = 0 ; i <n;i++){
			q.add(new chess(0,i,1));
			while(!q.isEmpty()){
				chess tmp =  q.poll();
				for(int k=tmp.i;k<n;k++){
					for(int l=0;l<n;l++){
						map[k][l]=0;
					}
				}
				map[tmp.i][tmp.j] =1;
				if(tmp.depth==n)
					count++;
				else{
					for(int  j = 0 ; j <n;j++){
						boolean checks=false;
						for(int k= 0;k<=tmp.i;k++ ){
							if(map[k][j]==1)
							{
								checks=true;
								break;
							}
						}
						if(!checks){
							int r=tmp.i+1,c=j;
							while(r>=0&&c<n){
								if(map[r][c]==1)
								{
									checks=true;
									break;
								}
								r--;
								c++;
							}
						}
						if(!checks){
							int r=tmp.i+1,c=j;
							while(r>=0&&c>=0){
								if(map[r][c]==1)
								{
									checks=true;
									break;
								}
								r--;
								c--;
							}
						}
						if(!checks){
							q.add(new chess(tmp.i+1,j,tmp.depth+1));
						}					}
				}
			}
			q.clear();
		}		
		System.out.println(count);
	}
	class chess implements Comparable<chess> {
		int i , j,depth;
		chess(int i,int j ,int depth){
			this.i = i ;
			this. j  =  j;
			this.depth =  depth;
		}
		@Override
		public int compareTo(chess arg0) {
			// TODO Auto-generated method stub
			if (this.depth > arg0.depth)
				return -1;
			return 1;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

