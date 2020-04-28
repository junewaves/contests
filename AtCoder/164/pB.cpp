#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t1 = (c - 1) / b;
    int t2 = (a - 1) / d;
    if (t2 < t1)
        cout << "No\n";
    else
        cout << "Yes\n";
}
