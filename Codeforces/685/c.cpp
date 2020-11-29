#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_DEBUG
#include "prettyprint.hpp"  // https://louisdx.github.io/cxx-prettyprint/
template<class T>
void dbg_print(const char* name, T last) {
    cerr << " [" << name << ": " << last << "]\n";
}
template<class H, class... T>
void dbg_print(const char* name, H head, T... tail) {
    const char* comma = strchr(name + 1, ',');
    (cerr << " [").write(name, comma - name) << ": " << head << "] ";
    dbg_print(comma + 2, tail...);
}
#define debug(...) dbg_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        array<int, 26> cnta{}, cntb{};
        for (char c : a) cnta[c - 'a']++;
        for (char c : b) cntb[c - 'a']++;
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            int x = min(cnta[i], cntb[i]);
            cnta[i] -= x;
            cntb[i] -= x;
            if (cnta[i] % k || cntb[i] % k) {
                ok = false;
                break;
            }
            cnta[i] /= k;
            cntb[i] /= k;
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        for (int i = 0; i < 26; i++) {
            if (cntb[i]) {
                for (int j = 0; j < i && cntb[i] > 0; j++) {
                    int x = min(cnta[j], cntb[i]);
                    cnta[j] -= x;
                    cntb[i] -= x;
                }
                if (cntb[i] > 0) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}