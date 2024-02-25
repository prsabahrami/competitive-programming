import java.util.*;

public class Main {
    static int N = (int) 2e5 + 10, MOD = (int) 1e9 + 7;
    static int[] P = new int[N], Q = new int [N];
    static String S;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        for (int q = sc.nextInt(); q > 0; q--) {
            int n = sc.nextInt(); 
            for (int i = 1; i <= n; i++) P[i] = sc.nextInt();
            S = sc.next();
            Vector<Integer> vec = new Vector<>(); // :((((((
            for (int i = 0; i < S.length(); i++) 
                if (S.charAt(i) == '0') { vec.add(i + 1); }
            Collections.sort(vec, new Comparator<Integer>() { // :((((((
                @Override public int compare(Integer x, Integer y) {
                    return P[x] - P[y];
                }
            });
            //System.out.println(vec);
            int lst = vec.size();
            for (int i = 0; i < vec.size(); i++) Q[vec.get(i)] = i + 1;
            vec.clear();
            for (int i = 0; i < S.length(); i++) 
                if (S.charAt(i) == '1') { vec.add(i + 1); }
            Collections.sort(vec, new Comparator<Integer>() { // :((((((
                @Override public int compare(Integer x, Integer y) {
                    return P[x] - P[y];
                }
            });
            for (int i = lst + 1; i <= n; i++) {
                Q[vec.get(i - lst - 1)] = i;
            }
            for (int i = 1; i <= n; i++) System.out.print(Q[i] + " ");
            System.out.println();
        }
        sc.close();
    }

}