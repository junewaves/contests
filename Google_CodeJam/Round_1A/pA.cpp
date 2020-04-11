// Code Jam Round 1A (4/11)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
int _n, n;
void solve() {
    cin >> n;
    string s;
    vector<vector<string>> vs;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<string> split;
        int p = 0;
        for (int j = 0; j < (int)s.size();) {
            if (s[j] == '*') {
                if (j > p)
                    split.emplace_back(s.substr(p, j - p));
                p = j;
                while (s[j] == '*')
                    j++;
                split.emplace_back(s.substr(p, j - p));
                p = j;
            } else {
                j++;
            }
        }
        if (p < (int)s.size() && s[p] != '*')
            split.emplace_back(s.substr(p, s.size() - p));
        vs.emplace_back(split);
    }
    for (auto& a : vs) {
        for (auto& b : a) {
            cout << b << ", ";
        }
        cout << endl;
    }
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