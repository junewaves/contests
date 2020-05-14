#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k);
    vector<int> cnt(k);
    int x, sum = 0;
    char c;
    for (int i = 0, j = 0; i < n; i++, j = (j + 1) % k) {
        cin >> c;
        x = c - '0';
        a[j].push_back(x);
        cnt[j] += x;
        sum += x;
    }
    int ans = INT_MAX;
    for (int b = 0; b < k; b++) {
        int s = 0, ms = 0, m1 = 0, mx1 = -1, mx2 = -2;
        int bs = a[b].size();
        for (int i = 0; i < bs; i++) {
            s += a[b][i] == 1 ? 1 : -1;
            if (s < 0) {
                s = 0;
                m1 = i + 1;
            }
            if (ms < s) {
                ms = s;
                mx2 = i;
                mx1 = m1;
            } else if (ms == s && i - m1 < mx2 - mx1) {
                mx2 = i;
                mx1 = m1;
            }
        }
        int n1 = 0;
        for (int i = 0; i < bs; i++) {
            if (mx1 <= i && i <= mx2) {
                if (a[b][i] == 0)
                    n1++;
            } else {
                if (a[b][i] == 1)
                    n1++;
            }
        }
        int need = sum - cnt[b] + n1;
        ans = min(ans, need);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
