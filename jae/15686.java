import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	int n,m;
	int bn= 0 ; 
	int map[][];
	int max =-1;
	ArrayList<place>q;
	ArrayList<home>queue_s;
	Main(){
		Scanner in =  new Scanner(System.in);
		map=new int[50][50];
		n  =  in.nextInt();
		m = in.nextInt();
		q=  new ArrayList<place>();
		queue_s = new ArrayList<home>();
		for(int i = 0 ; i <n ; i++)
			for(int j = 0 ; j<n ; j++){
				map[i][j] =in.nextInt();
				if(map[i][j]==2){
					bn++;
					q.add(new place(i,j));
				}
				else if(map[i][j] ==1){
					queue_s.add(new home(i,j));
				}
			}
		int arr[]=  new int[bn];
		for(int i = 0 ;i <bn ; i++)
			arr[i] = 0;
		check(arr,0,0);
		check(arr,0,1);
		System.out.println(max);
	}
	public void check(int arr[],int index,  int value){
		if(index>=bn){
			int counts=0;
			for(int  i = 0;i<index;i++){
				if(arr[i]==1)
					counts++;

			}
			if(counts==m){
				check_s(arr);
			}

			return;
		}
		int tmp_arr[] = new int[bn];
		for(int i  = 0 ; i <index;i++)
			tmp_arr[i] =arr[i];
		tmp_arr[index]=value;
		check(tmp_arr,index+1,0);
		check(tmp_arr,index+1,1);

	}
	public void check_s(int arr[]){
		int tmp_arr [] =new int [bn];
		int sum = 0;
		for(int i = 0;i<bn;i++)
			tmp_arr[i]=arr[i];
		for(int i = 0 ; i <queue_s.size();i++){
			int  tmp =-1;
			for(int  j = 0 ;j<bn;j++){
				if(tmp_arr[j]>=1)
					if((tmp==-1||tmp>Math.abs(q.get(j).i-queue_s.get(i).i)+Math.abs(q.get(j).j-queue_s.get(i).j))){
						tmp = Math.abs(q.get(j).i-queue_s.get(i).i)+Math.abs(q.get(j).j-queue_s.get(i).j);
						tmp_arr[j]++;
					}
			}
			sum+=tmp;
		}

		if(max==-1||max>sum){
			max = sum;
		}
	}
	class place  {
		int  i , j ;
		place(int i ,  int j ){
			this.i = i;
			this.j = j;
		}
	}
	class home {
		int i , j ;
		home (int i ,int  j ){
			this.i=i ;
			this.j=j;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}
}

