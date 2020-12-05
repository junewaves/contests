#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    string ans;
    while (n) {
        ans += 'a' + (n - 1) % 26;  
        n = (n - 1) / 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}