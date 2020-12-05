#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m;
    n = m % 10;
    if (n == 3)
        cout << "bon";
    else if (n <= 1 || n == 6 || n == 8)
        cout << "pon";
    else
        cout << "hon";
}
