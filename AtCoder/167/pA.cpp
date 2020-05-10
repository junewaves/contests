#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int ss = s.size(), tt = t.size();
    if (ss != tt - 1) {
        cout << "No";
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < ss; i++) {
        if (s[i] != t[i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No");
}
