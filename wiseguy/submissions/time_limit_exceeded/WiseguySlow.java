import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.RoundingMode;


public class WiseguySlow {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	/*
	  br = new BufferedReader(new FileReader("A-input.txt"));
	  pw = new PrintWriter(new BufferedWriter(new FileWriter("A-output.txt")));
	  br = new BufferedReader(new InputStreamReader(System.in));
      pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	  */
	public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int LIM = 500;
        BigDecimal dyn[][] = new BigDecimal[LIM+1][LIM+1]; 
        BigDecimal sum[][] = new BigDecimal[LIM+1][LIM+1]; 
        for(int i = 0;i < LIM+1;i++){
            for(int j = 0;j < LIM+1;j++){
                dyn[i][j] = new BigDecimal(0);
                sum[i][j] = new BigDecimal(0);
            }
        }
        dyn[0][0]= new BigDecimal(1);
        dyn[1][0]= new BigDecimal(1);

        for(int i = 0; i < LIM+1;i++) {
            if (i >= 2) {
                for(int a = 0;a < i;a++) {
                    int b = i-a-1; 
                    for(int h3=0;h3 < i;h3++) {
                        // h1 = h3, h2 <= h3
                        dyn[i][h3+1] = dyn[i][h3+1].add(dyn[a][h3].multiply(sum[b][h3+1].divide(new BigDecimal(i), 4, RoundingMode.HALF_UP)));
                        // h1 < h3, h2 = h3
                        dyn[i][h3+1] = dyn[i][h3+1].add(sum[a][h3].multiply(dyn[b][h3].divide(new BigDecimal(i), 4, RoundingMode.HALF_UP)));
                    }
                }
            }
            for(int a = 0;a < LIM;a++) {
                sum[i][a+1]=sum[i][a].add(dyn[i][a]);
            }
        }
        int T = readInt();
        for(int t = 0; t < T;t++){
            int N = readInt();
            BigDecimal ans = new BigDecimal(0);
            for(int i = 0;i < N;i++) {
                ans = ans.add((new BigDecimal(i).multiply(dyn[N][i])));
            }
            pw.printf("%.9f\n", ans);
        }
		pw.close();
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