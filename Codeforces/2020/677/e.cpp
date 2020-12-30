#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int64_t ans = 1;
    for (int i = n - 1; i > n / 2; i--)
        ans *= i;
    for (int i = 2; i < n / 2; i++) 
        ans *= i;
    cout << ans;
    return 0;
}