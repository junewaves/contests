#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> ch(26, 0);
    for (char c : s)
        ch[c - 'a']++;
    int n;
    cin >> n;
    vector<int> b(n), cand;
    vector<char> ans(n, '?');
    for (int& it : b)
        cin >> it;
    bool done = false;
    int x = 25;
    while (!done) {
        cand.clear();
        for (int i = 0; i < n; i++) {
            if (ans[i] != '?')
                continue;
            int dis = 0;
            for (int j = 0; j < n; j++)
                if (ans[j] != '?')
                    dis += abs(i - j);
            if (b[i] == dis)
                cand.push_back(i);
        }
        for (; x >= 0; x--) {
            if (ch[x] >= (int)cand.size()) {
                for (int idx : cand)
                    ans[idx] = char('a' + x);
                x--;
                break;
            }
        }
        done = true;
        for (char c : ans)
            done &= (c != '?');
    }
    for (char a : ans)
        cout << a;
    cout << '\n';
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
