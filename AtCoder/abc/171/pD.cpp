#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        sum += t;
        cnt[t]++;
    }
    int q;
    cin >> q;
    for (int i = 0, b, c; i < q; i++) {
        cin >> b >> c;
        cnt[c] += cnt[b];
        sum += 1ll * (c - b) * cnt[b];
        cnt[b] = 0;
        cout << sum << '\n';
    }
    return 0; 
}