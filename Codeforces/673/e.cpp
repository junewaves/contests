#include <bits/stdc++.h>
using namespace std;

int a[300005];
int64_t inv[32][2];
void recur(int bit, const vector<int>& ind) {
    if (bit < 0 || (int)ind.size() <= 1) return;
    int64_t cnt[2]{};
    vector<int> nxt[2];
    for (int i : ind) {
        int b = !!(a[i] & (1 << bit));
        inv[bit][b] += cnt[b ^ 1];
        cnt[b]++;
        nxt[b].push_back(i);
    }
    recur(bit - 1, nxt[0]);
    recur(bit - 1, nxt[1]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> all(n);
    iota(all.begin(), all.end(), 0);
    recur(30, all);
    int ans = 0;
    int64_t inverse = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (inv[i][0] > inv[i][1]);
        inverse += inv[i][b];
        ans = ans << 1 | b;
    }
    cout << inverse << ' ' << ans << '\n';
    return 0;
}