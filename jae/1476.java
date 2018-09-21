import java.util.Scanner;

public class Main {
	int e,s,m,i=1;
	Main(){
		Scanner in = new Scanner(System.in);
		e= in.nextInt();
		s= in.nextInt();
		m= in.nextInt();
		boolean check=false;
		while(true) {
			if(i%15==e%15&&i%28==s%28&&i%19==m%19)  	
				break;
			i++;
		}
		System.out.println(i);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}

