#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i < k; i++) {
        ll min_digit = 10, max_digit = -1, copy = n;
        while (copy) {
            min_digit = min(min_digit, copy % 10);
            max_digit = max(max_digit, copy % 10);
            copy /= 10;
        }
        ll p = min_digit * max_digit;
        if (p == 0) {
            break;
        }
        n += p;
    }
    std::cout << n << endl;
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
