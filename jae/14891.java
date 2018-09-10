import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	int K ;
	int wheel [][];
	int copywheel[][];
	int v;
	String a;
	ArrayList<Rotate> Rotation ;

	Main(){
		Scanner in =  new Scanner(System.in);
		Rotation  = new ArrayList<Rotate>();
		wheel  = new int  [4][8];
		int num;
		int clockwise;
		copywheel  = new int  [4][8];
		for(int i = 0; i <4 ; i ++){
			String a =  in.next();
			for(int  j = 0 ; j<8; j++)
				wheel [i][j] =  a.charAt(j)-48;
		}
		K =  in.nextInt();
		for(int  i =   0 ;   i <K  ; i++) {
			num =  in.nextInt();
			clockwise =  in.nextInt();
			Rotation.add(new Rotate(num-1,clockwise));
		}
		for(int  i = 0 ; i<Rotation.size();i++) 
			check(Rotation.get(i).num,Rotation.get(i).clockwise);
		for(int  i = 0 ; i <4;i++) 
			v +=wheel[i][0]*Math.pow(2, i);
		System.out.println(v);
		v= 0;
		Rotation.clear();

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();

	}
	public void check(int  num, int clockwise) {
		for(int i = 0;i<4 ; i++) {
			for(int j = 0; j<8;j++)
				copywheel[i][j] =  wheel[i][j];
		}
		switch(num) {
		case 0 :
			rotate(0,clockwise);
			if(wheel[0][2]!=wheel[1][6]) {
				rotate(1,-clockwise);
				if(wheel[1][2]!=wheel[2][6])
				{
					rotate(2,clockwise);
					if(wheel[2][2]!=wheel[3][6])
						rotate(3,-clockwise);
				}
			}
			break;
		case 1: 
			rotate(1,clockwise);
			if(wheel[0][2]!=wheel[1][6])
				rotate(0,-clockwise);
			if(wheel[1][2]!=wheel[2][6]) {
				rotate(2,-clockwise);
				if(wheel[2][2]!=wheel[3][6])
					rotate(3,clockwise);
			}
			break;
		case 2:
			rotate(2,clockwise);
			if(wheel[2][2]!=wheel[3][6])
				rotate(3,-clockwise);
			if(wheel[2][6]!=wheel[1][2]) {
				rotate(1,-clockwise);
				if(wheel[0][2]!=wheel[1][6])
					rotate(0,clockwise);
			}
			break;
		case 3:
			rotate(3,clockwise);
			if(wheel[2][2]!=wheel[3][6])
			{
				rotate(2,-clockwise);
				if(wheel[1][2]!=wheel[2][6])
				{
					rotate(1,clockwise);
					if(wheel[0][2]!=wheel[1][6])
						rotate(0,-clockwise);
				}
			}

			break;
		}
		for(int i = 0;i<4 ; i++) 
			for(int j = 0; j<8;j++)
				wheel[i][j] =  copywheel[i][j];

	}
	public void rotate(int num , int clockwises) {

		if(clockwises ==1) {
			int tmp =  copywheel[num][7];
			for(int i = 6;i>=0;i--) {
				copywheel[num][i+1] =  copywheel[num][i];		
			}
			copywheel[num][0] =tmp;
		}
		else {
			int tmp =  copywheel[num][0];
			for(int i = 0;i<7;i++) {
				copywheel[num][i] =  copywheel[num][i+1];		
			}
			copywheel[num][7] =tmp;
		}
	}
	class Rotate{
		int num, clockwise;
		Rotate(int num ,int clockwise){
			this.num = num;
			this.clockwise =clockwise;
		}
	}
}

