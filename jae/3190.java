import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
   int n,k,l,row,col,x,map[][],map2[][],head_r,head_c,head_d;
   char c;
   String a;
   Stack<body> mom;
   Queue<li> q ;
   li tmp;
   int dr []={0,0,-1,1};
   int dc []={1,-1,0,0};
   int time = 0;
   Main(){
      Scanner in = new Scanner(System.in);
      n = in.nextInt();
      k = in.nextInt();
      mom = new Stack<body>();
      mom.add(new body(1,1));
      map = new int[n+1][n+1];
      map2 =  new int[n+1][n+1];
      map2[1][1]=-1;
      head_r =1;head_c =1;head_d=0;
      q = new LinkedList<li>();
      for(int i = 0 ; i <k;i++) {
         row =in.nextInt();
         col = in.nextInt();
         map[row][col] = 2;
      }
      l =in.nextInt();
      for(int i = 0 ; i <l;i++) {
         a = in.next();
         x =Integer.parseInt(a);
         a = in.next();
         c = a.charAt(0);
         if(c=='L')
            q.add(new li(x,0));
         else
            q.add(new li(x,1));
      }
      if(!q.isEmpty())
         tmp =  q.poll();
      while(true){
         time++;
         head_r+=dr[head_d];
         head_c+=dc[head_d];
         if(head_r>n||head_c>n||head_r<=0||head_c<=0||(map2[head_r][head_c]==time-1&time!=1))
            break;
         if(map[head_r][head_c]==2){
            mom.add(new body(head_r,head_c));
            map[head_r][head_c] =0;
         }
         else{
            if(mom.size()>=2)
               for(int i =0 ; i<mom.size()-1;i++){
                  mom.get(i).row = mom.get(i+1).row;
                  mom.get(i).col = mom.get(i+1).col;
               }
            mom.get(mom.size()-1).row = head_r;
            mom.get(mom.size()-1).col = head_c;
         }   
         for(int i =mom.size()-1 ; i>=0;i--){
            if(map2[mom.get(i).row][mom.get(i).col]==time)
            {
               System.out.println(time);
               return;
            }
            map2[mom.get(i).row][mom.get(i).col]=time;
         }
         if(tmp!=null&&tmp.time==time){
            switch(head_d){
            case 0:
               if(tmp.direction==0)
                  head_d =2;
               else
                  head_d =3;
               break;
            case 1:
               if(tmp.direction==0)
                  head_d =3;
               else
                  head_d =2;
               break;
            case 2:
               if(tmp.direction==0)
                  head_d =1;
               else
                  head_d =0;
               break;
            case 3:
               if(tmp.direction==0)
                  head_d =0;
               else
                  head_d =1;
               break;
            }
            tmp =null;
         }
         if(tmp==null)
            if(!q.isEmpty())
               tmp =  q.poll();   
      }
      System.out.println(time);
   }
   class body{
      int row,col;
      body(int row,int col){
         this.row = row;
         this.col = col;
      }
   }
   class li{
      int time,direction;
      li (int time,int direction){
         this.time = time;
         this.direction = direction;
      }
   }
   public static void main(String[] args) {
      // TODO Auto-generated method stub
      new Main();
   }
}
