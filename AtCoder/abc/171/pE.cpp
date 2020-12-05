#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int& it : a)
        cin >> it, x ^= it;
    for (int it : a) 
        cout << (x ^ it) << " ";
    cout << endl;
    return 0;
}