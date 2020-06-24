#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ti, tmax, sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ti;
        sum += ti;
        tmax = max(tmax, ti);
    }
    sum = tmax * n - sum;
    if (m <= sum)
        cout << tmax << endl;
    else
        cout << (m - sum + n - 1) / n + tmax << endl;
    return 0;
}
