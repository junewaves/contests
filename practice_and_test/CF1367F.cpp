#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    vector<vector<int>> pos(b.size());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        pos[a[i]].push_back(i);
    }
    int last = -1, mx = 0, cur = 0;
    for (int i = 0, j; i < (int)b.size(); i++) {
        if (pos[i][0] > last) {
            // we can append all of i to the sequence
            cur += pos[i].size();
        } else {
            // append part of i to the old sequence
            j = pos[i].end() - lower_bound(pos[i].begin(), pos[i].end(), last);
            mx = max(mx, cur + j);
            // max sequence containing only i and i - 1
            for (int k = 0; k < (int)pos[i - 1].size() - 1; k++) {
                j = pos[i].end() -
                    lower_bound(pos[i].begin(), pos[i].end(), pos[i - 1][k]);
                mx = max(mx, k + 1 + j);
            }
            // starting a new sequence with part of i - 1
            j = lower_bound(pos[i - 1].begin(), pos[i - 1].end(), pos[i][0]) -
                pos[i - 1].begin();
            cur = j + pos[i].size();
        }
        mx = max(mx, cur);
        last = pos[i].back();
    }
    cout << n - mx << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}