#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> fac;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            fac[2]++;
            while(a % 2 == 0) a /= 2;
        }
        for (int j = 3; (ll)j * j <= a; j += 2) {
            bool yes = 0;
            while (a % j == 0) a /= j, yes = 1;
            if (yes) fac[j]++;
        }
        if (a > 1) fac[a]++;
    }
    bool s = true, p = true;
    for (auto [f, c] : fac) {
        if (c == n) s = false;
        if (c > 1) p = false;
    }
    if (p) cout << "pairwise coprime\n";
    else if (s) cout << "setwise coprime\n";
    else cout << "not coprime\n";
    return 0;
}