#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int g = 0, inGroup = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= inGroup + 1) {
            g++;
            inGroup = 0;
        } else {
            inGroup++;
        }
    }
    cout << g << endl;
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
