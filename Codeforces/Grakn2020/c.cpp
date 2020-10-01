#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int L = 0, R = n + 1;
    double t1 = 0.0, t2 = 0.0, s1 = 1.0, s2 = 1.0;
    while (L + 1 < R) {
        double t3 = t1 + double(a[L + 1] - a[L]) / s1;
        double t4 = t2 + double(a[R] - a[R - 1]) / s2;
        if (t3 < t4) {
            t1 = t3;
            s1 += 1.0;
            L++;
        } else {
            t2 = t4;
            s2 += 1.0;
            R--;
        }
    }
    double p1 = a[L], p2 = a[R];
    if (t1 < t2) {
        p1 += (t2 - t1) * s1;
    } else if (t1 > t2) {
        p2 -= (t1 - t2) * s2;
    }
    cout << max(t1, t2) + (p2 - p1) / (s1 + s2) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    cout << fixed << setprecision(9);
    while (tt--)
        solve();
    return 0;
}