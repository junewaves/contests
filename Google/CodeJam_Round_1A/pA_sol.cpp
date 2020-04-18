// Code Jam Round 1A (4/11)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
int _n, n;
void solve() {
    cin >> n;
    vector<string> strs(n);
    vector<int> pre(n, 0), suf(n, 0);
    int max_pre = 0, max_suf = 0;
    // input strings, get max prefix & suffix length
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        int len = strs[i].size();
        for (int j = 0; j < len; j++) {
            if (strs[i][j] == '*')
                break;
            pre[i]++;
        }
        if (pre[i] > pre[max_pre])
            max_pre = i;
        for (int j = len - 1; j >= 0; j--) {
            if (strs[i][j] == '*')
                break;
            suf[i]++;
        }
        if (suf[i] > suf[max_suf])
            max_suf = i;
    }
    // compare prefix and suffix
    for (int s_idx = 0; s_idx < n; s_idx++) {
        const string& s = strs[s_idx];
        if (pre[max_pre] > 0 && s_idx != max_pre) {
            for (int i = 0; i < pre[s_idx]; i++) {
                if (s[i] != strs[max_pre][i]) {
                    cout << "*\n";
                    return;
                }
            }
        }
        if (suf[max_suf] > 0 && s_idx != max_suf) {
            for (int i = 1; i <= suf[s_idx]; i++) {
                int sa = s.size(), sb = strs[max_suf].size();
                if (s[sa - i] != strs[max_suf][sb - i]) {
                    cout << "*\n";
                    return;
                }
            }
        }
    }
    // contruct output string
    for (int i = 0; i < pre[max_pre]; i++)
        cout << strs[max_pre][i];

    for (int i = 0; i < n; i++) {
        for (int j = pre[i] + 1; j < (int)strs[i].size() - suf[i]; j++) {
            if (strs[i][j] != '*')
                cout << strs[i][j];
        }
    }

    int ss = strs[max_suf].size();
    for (int i = suf[max_suf]; i > 0; i--)
        cout << strs[max_suf][ss - i];
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": ";
        solve();
    }
    return 0;
}