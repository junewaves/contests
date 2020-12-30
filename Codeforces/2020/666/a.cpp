#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> cnt(26);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[c - 'a']++;
        }
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0 && cnt[i] % n != 0) {
            ok = false;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}