import java.io.*;
import java.util.*;


public class Enigma{

    private static BufferedReader br;
	private static StringTokenizer st;
    private static Scanner sc;
    private static PrintWriter pw;
    
    static final int LIM = 22;
    static int R,C,N;
    static boolean uH[][] = new boolean[LIM][LIM];
    static boolean uV[][] = new boolean[LIM][LIM];
    static int lenH[][] = new int[LIM][LIM];
    static int lenV[][] = new int[LIM][LIM];
    static Character grid[][] = new Character[LIM][LIM];
    static List<String>word = new ArrayList<>();
    static List<Integer>len = new ArrayList<>();

	/*
	  br = new BufferedReader(new FileReader("A-input.txt"));
	  pw = new PrintWriter(new BufferedWriter(new FileWriter("A-output.txt")));
	  br = new BufferedReader(new InputStreamReader(System.in));
      pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	  */
	public static void main(String[] args) throws IOException{
        //br = new BufferedReader(new InputStreamReader(System.in));
        // pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        sc.nextLine(); // garbagge
        for (int r = 0;r < R;r++) {
            String line = sc.nextLine(); 
            for(int c = 0;c < C;c++) {
                grid[r][c] = line.charAt(c);
            }
        }
        N = sc.nextInt();
        sc.nextLine(); // garbage
        for(int i = 0;i < N;i++) {
            String line = sc.nextLine();
            word.add(line);
        }
        // sort the word by length
        Collections.sort(word, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2){
                return s2.length() - s1.length();
            }
        });

        for(int i = 0;i < word.size();i++) {
            len.add(word.get(i).length());
        }
        // precompute horizontal grid lengths
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '.') {
                    int k;
                    for (k = j + 1; k < C && grid[i][k] == '.'; k++)
                    ;
                    lenH[i][j] = k - j;
                    j = k;
                }
            }
        }
        // Precompute vertical grid lengths.
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (grid[j][i] == '.') {
                    int k;
                    for (k = j + 1; k < R && grid[k][i] == '.'; k++);
                    lenV[j][i] = k - j;
                    j = k;
                }
            }
        }
        rec(0);
		// pw.close();
   }

   public static Boolean rec(int i) {
        if (i == N) {
            for (int r = 0; r < R; r++) {
                for(int c = 0;c < C;c++) {
                    System.out.printf("%c", grid[r][c]);
                }
                System.out.println();
            }
            return true;
        }
        // Place next word horizontally.
        Boolean chg[] = new Boolean[21];
        for (int y = 0; y < R; y++) {
            for (int x = 0; x + len.get(i) - 1 < C; x++) {
            if (lenH[y][x] == len.get(i) && !uH[y][x]) {
                // Check validity.
                int j;
                for (j = 0; j < len.get(i); j++) {
                    if (grid[y][x + j] != '.' && grid[y][x + j] != word.get(i).charAt(j)) break;
                }
                // Try it.
                if (j == len.get(i)) {
                    // Place word.
                    Arrays.fill(chg, false);
                    for (j = 0; j < len.get(i); j++) {
                        if (grid[y][x + j] == '.') {
                            grid[y][x + j] = word.get(i).charAt(j);
                            chg[j] = true;
                        }
                    }
                    uH[y][x] = true;
                    // Recurse.
                    if (rec(i + 1)) return true;
                    // Remove word.
                    uH[y][x] = false;
                    for (j = 0; j < len.get(i); j++) {
                        if (chg[j]) {
                            grid[y][x + j] = '.';
                        }
                    }
                }
            }
            }
        }
        // Place next word vertically.
        for (int y = 0; y + len.get(i) - 1 < R; y++) {
            for (int x = 0; x < C; x++) {
            if (lenV[y][x] == len.get(i) && !uV[y][x]) {
                // Check validity.
                int j;
                for (j = 0; j < len.get(i); j++) {
                    if (grid[y + j][x] != '.' && grid[y + j][x] != word.get(i).charAt(j)) break;
                }
                // Try it.
                if (j == len.get(i)) {
                    // Place word.
                    Arrays.fill(chg, false);
                    for (j = 0; j < len.get(i); j++) {
                        if (grid[y + j][x] == '.') {
                            grid[y + j][x] = word.get(i).charAt(j);
                            chg[j] = true;
                        }
                    }
                    uV[y][x] = true;
                    // Recurse.
                    if (rec(i + 1)) return true;
                    // Remove word.
                    uV[y][x] = false;
                    for (j = 0; j < len.get(i); j++) {
                        if (chg[j]) {
                            grid[y + j][x] = '.';
                        }
                    }
                }
            }
            }
        }
        return false;
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
