// Codeforces Round #633 (Div. 2) (4/12)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    vector<int> num2(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    int s = n / 2;
    for (int i = 0; i < s; i++) {
        num2[i * 2] = num[n - i - 1];
        num2[i * 2 + 1] = num[i];
    }
    if (n % 2)
        num2[n - 1] = num[n / 2];
    for (int i = n - 1; i >= 0; i--) {
        cout << num2[i] << " ";
    }
    cout << endl;
    num.clear();
    num2.clear();
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