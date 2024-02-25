#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1 << 12;
int M[N], n, k;

int ask(int p) { char ret[2]; printf("? %d\n", p); fflush(stdout); scanf("%s", ret); return ret[0] != 'N'; }

int main() {
    scanf("%d%d", &n, &k);
    if (n < 2) return !printf("! 1\n");
    if (k < 2) {
        fill(M, M + n + 1, 1);
        for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) 
            ask(i), M[j] &= !ask(j), printf("R\n"), fflush(stdout);
        int ret = 0;
        for (int i = 1; i <= n; i++) ret += M[i];
        printf("! %d\n", ret);
        fflush(stdout);
    }
    for (int i = 1; i <= n; i++) 
        M[i] = !ask(i);
    printf("R\n");
    for (int i = 1; i <= n / k; i++) 
        for (int j = i + 1; j <= n / k; j++) {
            for (int l = i * k - k + 1; l <= i * k - k / 2; l++) if (M[l]) ask(l);
            for (int l = j * k - k + 1; l <= j * k - k / 2; l++) if (M[l]) M[l] &= !ask(l);
            for (int l = i * k; l > i * k - k / 2; l--) if (M[l]) M[l] &= !ask(l);
            printf("R\n");
            for (int l = i * k - k + 1; l <= i * k - k / 2; l++) if (M[l]) ask(l);
            for (int l = j * k; l > j * k - k / 2; l--) if (M[l]) M[l] &= !ask(l);
            for (int l = i * k; l > i * k - k / 2; l--) if (M[l]) M[l] &= !ask(l);
            printf("R\n");
        }
    int ret = 0;
    for (int i = 1; i <= n; i++) ret += M[i];
    printf("! %d\n", ret);
    fflush(stdout);
    return 0;
}