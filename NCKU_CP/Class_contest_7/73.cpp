#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, a, b, y[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        y[i] = y[i - 1] ^ a;
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << (y[b] ^ y[a - 1]) << '\n';
    }
    return 0;
}
