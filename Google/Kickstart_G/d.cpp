#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double answer = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            answer += (double)a[j] / (i - j + 1);
        }
        for (int j = i + 1; j < n; j++) {
            answer += (double)a[j] / (j - i);
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    cout << fixed << setprecision(10);
    for (int cn = 1; cn <= tt; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}