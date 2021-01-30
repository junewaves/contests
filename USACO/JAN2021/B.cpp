#include <bits/stdc++.h>
using namespace std;

int code(char c) {
    if (c == '?')
        return 0;
    else
        return c - 'A' + 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pre(n + 2), suf(n + 2);
    int last[27];
    memset(last, -1, 27 * 4);
    s = '?' + s + '?';
    last[0] = 0;
    for (int i = 1; i <= n; i++) {
        int idx = s[i] - 'A' + 1;
        int add = any_of(last, last + idx,
                         [x=last[idx]](int p) { return p > x; });
        pre[i] = pre[i - 1] + add;
        last[idx] = i;
    }
    for (int i = 1; i < 27; i++)
        last[i] = n + 2;
    last[0] = n + 1;
    for (int i = n; i >= 1; i--) {
        int idx = s[i] - 'A' + 1;
        int add = any_of(last, last + idx,
                         [x=last[idx]](int p) { return p < x; });
        suf[i] = suf[i + 1] + add;
        last[idx] = i;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[l - 1] + suf[r + 1] << '\n';
    }
}
