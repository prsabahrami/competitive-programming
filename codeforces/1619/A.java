import java.util.*;

public class Main {
    static int N = (int) 2e5 + 10, MOD = (int) 1e9 + 7;
    static int[] P = new int[N], Q = new int [N];
    static String S;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        for (int q = sc.nextInt(); q > 0; q--) {
            String S; S = sc.next();
            int x = S.length(); 
            if (x % 2 == 1) { System.out.println("NO"); continue; }
            int f = 1;
            for (int i = 0; i < x / 2; i++) 
                if (S.charAt(i) != S.charAt(i + x / 2)) f = 0;
            if (f == 0) { System.out.println("NO"); continue; }
            System.out.println("YES");
        }
        sc.close();
    }

}