#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        if (n > k)
            cout << (n % k ? 2 : 1) << '\n';
        else
            cout << (k + n - 1) / n << '\n';
    }
    return 0;
}
