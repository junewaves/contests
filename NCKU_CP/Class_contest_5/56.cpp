#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "No\n";
        return 0;
    }
    int a, b;
    if (n & 1) {
        a = n / 2 + 1;
        b = n / 2;
    } else {
        a = b = n / 2;
    }
    cout << "Yes\n";
    cout << a << " " << b << '\n';
    for (int i = 0, j = 1; i < a; i++, j += 2)
        cout << j << " ";
    cout << '\n';
    for (int i = 0, j = 2; i < b; i++, j += 2)
        cout << j << " ";
    cout << '\n';
    return 0;
}
