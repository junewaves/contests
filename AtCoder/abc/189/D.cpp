#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int64_t F = 1, T = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "AND")
            F = 2 * F + T;
        else 
            T = 2 * T + F;
    }
    cout << T << '\n';
    return 0;
}
