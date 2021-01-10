#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &it : a) cin >> it;
    for (int &it : b) cin >> it;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    cout << (sum == 0 ? "Yes\n" : "No\n");
    return 0;
}