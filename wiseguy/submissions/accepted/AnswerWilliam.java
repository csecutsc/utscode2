import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.RoundingMode;


public class AnswerWilliam {

    private static BufferedReader br;
    private static Scanner sc;
	private static StringTokenizer st;
	private static PrintWriter pw;

	/*
	  br = new BufferedReader(new FileReader("A-input.txt"));
	  pw = new PrintWriter(new BufferedWriter(new FileWriter("A-output.txt")));
	  br = new BufferedReader(new InputStreamReader(System.in));
      pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	  */
	public static void main(String[] args) throws IOException{
        // br = new BufferedReader(new InputStreamReader(System.in));
        // br = new BufferedReader(new InputStreamReader(System.in));
        // pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        sc = new Scanner(System.in);
        int LIM = 500;
        double dyn[][] = new double[LIM+1][LIM+1]; 
        double sum[][] = new double[LIM+1][LIM+1]; 
        for(int i = 0;i < LIM+1;i++){
            for(int j = 0;j < LIM+1;j++){
                dyn[i][j] = 0; 
                sum[i][j] = 0; 
            }
        }
        dyn[0][0]= 1; 
        dyn[1][0]= 1; 

        for(int i = 0; i < LIM+1;i++) {
            if (i >= 2) {
                for(int a = 0;a < i;a++) {
                    int b = i-a-1; 
                    for(int h3=0;h3 < i;h3++) {
                        // h1 = h3, h2 <= h3
                        dyn[i][h3+1]+=dyn[a][h3]*sum[b][h3+1]/i;
                        // h1 < h3, h2 = h3
                        dyn[i][h3+1]+=sum[a][h3]*dyn[b][h3]/i;
                    }
                }
            }
            for(int a = 0;a < LIM;a++) {
                sum[i][a+1]=sum[i][a]+dyn[i][a];
            }
        }
        int T = sc.nextInt();
        for(int t = 0; t < T;t++){
            int N = sc.nextInt();
            double ans = 0; 
            for(int i = 0;i < N;i++) {
                ans+=i*dyn[N][i];
            }
            System.out.printf("%.9f\n", ans);
        }
   }

  //----------------Fast Input------------------
  private static void exitImmediately(){
	  pw.close();
	  System.exit(0);
  }
  private static long readLong() throws IOException{
	  return Long.parseLong(nextToken());
  }
  private static double readDouble() throws IOException{
	  return Double.parseDouble(nextToken());
  }
  private static int readInt() throws IOException{
	  return Integer.parseInt(nextToken());
  }
  private static String nextToken() throws IOException{
	  while(st == null || !st.hasMoreTokens()){
		  if(!br.ready()){
			  exitImmediately();
		  }
		  st = new StringTokenizer(br.readLine().trim());
	  }
	  return st.nextToken();
  }
  //--------------------------------------------------------
}