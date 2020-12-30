#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN = 1e7 + 1;
int pr[mxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // precompute the largest prime factor for every number
    for (int i = 2; i < mxN; i++)
        if (!pr[i])
            for (int j = i; j < mxN; j += i)
                pr[j] = i;
    int n;
    cin >> n;
    vector<int> b(n, -1), c(n, -1);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        vector<int> fact;
        while (a > 1) {
            int p = pr[a];
            while (a % p == 0)
                a /= p;
            fact.push_back(p);
        }
        if (fact.size() >= 2) {
            b[i] = fact[0];
            c[i] = 1;
            for (int j = 1; j < (int)fact.size(); j++)
                c[i] *= fact[j];
        }
    }
    for (int vb : b)
        cout << vb << ' ';
    cout << '\n';
    for (int vc : c)
        cout << vc << ' ';
    cout << '\n';
    return 0;
}
