#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int cnt[31]{};
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 2; j * j <= x; j++) {
            int c = 0;
            while (x % j == 0) {
                c++;
                x /= j;
            }
            cnt[j] = max(cnt[j], c);
        }
        if (x > 1) cnt[x] = max(cnt[x], 1);
    }
    int64_t ans = 1;
    for (int i = 2; i <= n; i++) { 
        for (int j = 0; j < cnt[i]; j++)
            ans *= i;
    }
    cout << ans + 1 << '\n';
    return 0;
}