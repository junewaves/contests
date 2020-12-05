#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += a[i];
    cout << ans << endl;
    return 0;
}