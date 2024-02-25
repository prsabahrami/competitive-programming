import java.util.*;

public class a {
    static int[] A = new int[3]; static int N = (int) 1e5 + 10, MOD = (int) 1e9 + 7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int t = sc.nextInt(); t > 0; t--) {
            for (int i = 0; i < 3; i++) {
                A[i] = sc.nextInt();
            }
            Arrays.sort(A);
            if (A[2] == A[1] + A[0]) System.out.println("YES");
            else {
                if (A[0] == A[1] && A[2] % 2 == 0) System.out.println("YES");
                else if (A[1] == A[2] && A[0] % 2 == 0) System.out.println("YES");
                else System.out.println("NO");
            }
        }
        sc.close();
    }
}