import java.util.Scanner;

public class Main2 {
	int map[];
	
	int n ;
	Main2(){
		Scanner  in  = new Scanner(System.in);
		n =  in.nextInt();
		map = new int[1000001];
		map[1]=0;
		map[2]=1;
		map[3]=1;
		for(int i = 4;i<1000001;i++) {
			int min = map[i-1];
			if(i%2==0) {
				if(min>map[i/2])
					min = map[i/2];
			}
			if(i%3==0)
				if(min>map[i/3])
					min = map[i/3];
			map[i] = min+1;
		}
		System.out.println(map[n]);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main2();
	}

}

