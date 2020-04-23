#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 9) {
        printf("%d\n", n);
        return 0;
    }
    int cnt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int m = 9;
    while (n > 1 && m > 1) {
        if (n % m == 0) {
            n /= m;
            cnt[m]++;
        } else {
            m--;
        }
    }
    if (n > 1) {
        puts("-1");
        return 0;
    }
    for (int i = 2; i <= 9; i++)
        for (int j = 0; j < cnt[i]; j++)
            printf("%d", i);
    puts("");
}
