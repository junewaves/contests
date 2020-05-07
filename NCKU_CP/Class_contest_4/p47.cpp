#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[j] = c[j - 1] + 1;
            } else {
                d[j] = max(c[j], d[j - 1]);
            }
        }
        if (i != n)
            copy(d.begin(), d.end(), c.begin());
    }
    cout << d[n] << endl;
    return 0;
}
