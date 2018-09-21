import java.util.*;

public class AnswerWilliam {
    private static Scanner sc;

    public static final int MAXR = 5005, MAXC = 5005;

    public static int R, C, total = 0, components = 0;
    public static Character G[][] = new Character[MAXR][MAXC];
    public static int lcol[][] = new int[MAXR][MAXC];
    public static int rcol[][] = new int[MAXR][MAXC];
    public static int urow[][] = new int[MAXR][MAXC]; 
    public static int drow[][] = new int [MAXR][MAXC];

    public static void main(String[]args){
        sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        sc.nextLine(); // garbage
        for (int r = 0; r < R; r++) {
            String str = sc.nextLine();
            for(int c = 0;c < C ;c++) {
                G[r][c] = str.charAt(c);
            }
        }
        initPointers();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (G[i][j] == 'x') {
                    flood(i, j);
                    components++;
                }
            }
        }
        System.out.println(total - components);
    }

    public static void initPointers(){
        for(int i = 0;i < MAXR;i++) {
            Arrays.fill(lcol[i], -1);
            Arrays.fill(rcol[i], -1);
            Arrays.fill(urow[i], -1);
            Arrays.fill(drow[i], -1);
        }
        int curr;
        for (int i = 0; i < R; i++) {
            curr = -1;
            for (int j = 0; j < C; j++) {
                if (G[i][j] == 'x') {
                    lcol[i][j] = curr;
                    curr = j;
                }
            }
            curr = -1;
            for (int j = C - 1; j >= 0; j--) {
                if (G[i][j] == 'x') {
                    rcol[i][j] = curr;
                    curr = j;
                }
            }
        }
        for (int j = 0; j < C; j++) {
            curr = -1;
            for (int i = 0; i < R; i++) {
                if (G[i][j] == 'x') {
                    urow[i][j] = curr;
                    curr = i;
                }
            }
            curr = -1;
            for (int i = R - 1; i >= 0; i--) {
                if (G[i][j] == 'x') {
                    drow[i][j] = curr;
                    curr = i;
                }
            }
        }
    } 

    public static void update_pointers(int r, int c) {
        if (lcol[r][c] != -1) {
            if (rcol[r][c] != -1) {
                rcol[r][lcol[r][c]] = rcol[r][c];
                lcol[r][rcol[r][c]] = lcol[r][c];
            } else {
                rcol[r][lcol[r][c]] = -1;
            }
        }
        if (urow[r][c] != -1) {
            if (drow[r][c] != -1) {
                drow[urow[r][c]][c] = drow[r][c];
                urow[drow[r][c]][c] = urow[r][c];
            } else {
                drow[urow[r][c]][c] = -1;
            }
        }
        if (rcol[r][c] != -1) {
            if (lcol[r][c] != -1) {
                lcol[r][rcol[r][c]] = lcol[r][c];
                rcol[r][lcol[r][c]] = rcol[r][c];
            } else {
                lcol[r][rcol[r][c]] = -1;
            }
        }
        if (drow[r][c] != -1) {
            if (urow[r][c] != -1) {
                urow[drow[r][c]][c] = urow[r][c];
                drow[urow[r][c]][c] = drow[r][c];
            } else {
                urow[drow[r][c]][c] = -1;
            }
        }
    }


    public static void flood(int r, int c) {
        Queue< Pair<Integer, Integer> > q = new LinkedList<>();
        q.add(new Pair<Integer,Integer>(r, c));
        while(!q.isEmpty()){
            Pair<Integer,Integer> p = q.remove();
            r = p.first;
            c = p.second;
            if (G[r][c] == '.') {
                continue;
            }
            total++;
            G[r][c] = '.';
            update_pointers(r, c);
            if (lcol[r][c] != -1) q.add(new Pair<Integer,Integer>(r, lcol[r][c]));
            if (urow[r][c] != -1) q.add(new Pair<Integer,Integer>(urow[r][c], c));
            if (rcol[r][c] != -1) q.add(new Pair<Integer,Integer>(r, rcol[r][c]));
            if (drow[r][c] != -1) q.add(new Pair<Integer,Integer>(drow[r][c], c));
        }
    }

    static class Pair<S, T> {
        S first;
        T second;
        public Pair(S first, T second){
            this.first = first;
            this.second = second;
        }
    }
}