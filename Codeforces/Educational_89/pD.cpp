#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// this is TLE
void solve() {
    int n;
    cin >> n;
    vector<int> b(n, -1), c(n, -1);
    for (int j = 0, a; j < n; ++j) {
        cin >> a;
        vector<int> f;
        for (int i = 2; (ll)i * i <= a; i++) {
            int t = 0;
            while (a % i == 0)
                a /= i, t++;
            if (t)
                f.push_back(i);
        }
        if (a != 1)
            f.push_back(a);
        if (f.size() >= 2) {
            b[j] = f[0];
            c[j] = 1;
            for (int i = 1; i < (int)f.size(); ++i)
                c[j] *= f[i];
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
