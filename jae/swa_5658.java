import java.util.PriorityQueue;
import java.util.Scanner;
public class Solution {
	int t,n,k,cnts=0;
	int map[];
	PriorityQueue<num>q;
	Solution(){
		Scanner sc= new Scanner(System.in);
		t= sc.nextInt();
		while(cnts<t) {
			n = sc.nextInt();
			int num = n/4;
			k =  sc.nextInt();
			map = new int[n+1];
			q= new PriorityQueue();
			String a = sc.next();
			for(int i = 0; i <n;i++)
				map[i] = a.charAt(i);
			for(int i = 0; i <n;i++)	
			{
				if(map[i]>=48&&map[i]<65)
					map[i]-=48;
				else
					map[i]-=55;		
			}
			while(num-->0) {
				int tmp=0;
				for(int  i =0;i<4;i++)
				{
					tmp=0;
					for(int  j =0;j<n/4;j++) 
						tmp+=Math.pow(16, n/4-j-1)*map[(n/4)*i+j];
					q.add(new num(tmp));
				}
				tmp =map[n-1];
				for(int i =  n-1; i>0;i-- )
					map[i]= map[i-1];
				map[0]=tmp;
			}
			int cnt =0;
			int pre = -1;
			while(!q.isEmpty()) {
				int tmp =q.poll().nums;
				if(pre!=tmp)
					cnt++;
				pre=tmp;
				if(cnt==k) {
					System.out.println("#"+(cnts+1)+" "+tmp);
					break;
				}	
			}
			cnts++;
			q.clear();
		}
	}
	class num implements Comparable<num>{
		int nums;
		num(int nums){
			this.nums=nums;
		}
		@Override
		public int compareTo(num arg0) {
			// TODO Auto-generated method stub
			if(this.nums>arg0.nums)
				return -1;
			return 1;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Solution();
	}
}

