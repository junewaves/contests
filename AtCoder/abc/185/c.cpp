#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int64_t ans = 1;
    bool used[12]{};
    for (int i = 0; i < 11; i++) {
        n--;
        ans *= n;
        for (int j = 2; j <= 11; j++) {
            if (!used[j] && ans % j == 0) {
                ans /= j;
                used[j] = true;
            }
        }
    }
    cout << ans << '\n';
}
