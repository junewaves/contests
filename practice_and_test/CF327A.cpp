#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    int diff = 0, ones = 0, max_dif = 0, min_dif = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ones += t;
        if (t == 1) {
            diff -= 1;
            min_dif = min(min_dif, diff);
        } else {
            diff += 1;
            max_dif = max(max_dif, diff - min_dif);
        }
    }
    if (ones == n)
        cout << n - 1 << endl;
    else
        cout << max_dif + ones << endl;
}