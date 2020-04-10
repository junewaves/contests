#include <stdio.h>
int main() {
    int n;
    long long k, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld", &k, &x);
        printf("%lld\n", (k - 1) * 9 + x);
    }
}