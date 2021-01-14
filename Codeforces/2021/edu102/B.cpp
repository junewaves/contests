#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        size_t len = lcm(s.size(), t.size());
        string ns, nt;
        while (ns.size() < len)
            ns += s;
        while (nt.size() < len)
            nt += t;
        if (ns == nt)
            cout << ns << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
