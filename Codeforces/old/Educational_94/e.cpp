#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int consider(int l, int r, vector<int>& a) {
    if (r - l == 1) return int(a[l] > 0);
    int mn = INT_MAX, cnt = 1;
    for (int i = l; i < r; i++) {
        if (a[i] < mn) {
            mn = a[i];
            cnt = 1;
        } else if (a[i] == mn) {
            cnt++;
        }
    }
    int sum = mn;
    int prv = l;
    for (int i = l; i < r; i++) {
        a[i] -= mn;
        if (a[i] == 0) {
            if (i > prv)
                sum += consider(prv, i, a);
            prv = i + 1;
        }
    }
    if (prv < r)
        sum += consider(prv, r, a);
    return min(r - l, sum);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a) cin >> it;
    cout << consider(0, n, a) << '\n';
    return 0;
}