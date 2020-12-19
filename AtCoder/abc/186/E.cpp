#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, s, k;
        cin >> n >> s >> k;
        int g = gcd(n, k);
        if (s % g != 0) {
            cout << "-1\n";
            continue;
        }
        s /= g, n /= g, k /= g;
        mint::set_mod(n);
        cout << (mint(n - s) / k).val() << '\n';
    }
    return 0;
}