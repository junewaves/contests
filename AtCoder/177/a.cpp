#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int d, t, s;
    cin >> d >> t >> s;
    cout << (t * s >= d ? "Yes\n" : "No\n");
    return 0;
}