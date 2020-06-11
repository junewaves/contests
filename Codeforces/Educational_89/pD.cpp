#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n, -1), c(n, -1);
    for (int& v : a)
        cin >> v;
    for (int j = 0; j < n; ++j) {
        for (int i = 2; (ll)i * i <= a[j]; i++) {
            if (a[j] % i == 0) {
                if (__gcd(i + a[j] / i, a[j]) == 1) {
                    b[j] = i;
                    c[j] = a[j] / i;
                    break;
                }
            }
        }
    }
    for (int i : b)
        cout << i << ' ';
    cout << '\n';
    for (int i : c)
        cout << i << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
