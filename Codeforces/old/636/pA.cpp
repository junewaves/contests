// Codeforces Round #636 (Div. 3) (4/21)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int n;
    cin >> n;
    int t = 1, k = 2;
    while (n % (t + k) != 0) {
        t += k;
        k <<= 1;
    }
    cout << n / (t + k) << endl;
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
