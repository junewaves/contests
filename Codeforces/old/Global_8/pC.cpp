#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int di[7] = { 1, 2, 2, 2, 1, 0, 0 };
// const int dj[7] = { 0, 0, 1, 2, 2, 2, 1 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    // cout << 7 * n + 8 << '\n';
    cout << 3 * n + 4 << '\n';
    cout << "0 0\n";
    // int oi = 0, oj = 0;
    for (int i = 0; i <= n; i++) {
        cout << i << ' ' << i + 1 << '\n';
        cout << i + 1 << ' ' << i << '\n';
        cout << i + 1 << ' ' << i + 1 << '\n';
        // for (int k = 0; k < 7; k++) {
        //     cout << oi + di[k] << " " << oj + dj[k] << '\n';
        // }
        // oi += 2;
        // oj += 2;
    }
    return 0;
}
