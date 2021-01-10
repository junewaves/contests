#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int x;
    cin >> x;
    vector<int> a(1 << x);
    for (int &it : a) cin >> it;
    int m = 1 << (x - 1);
    int i = max_element(a.begin(), a.begin() + m) - a.begin();
    int j = max_element(a.begin() + m, a.end()) - a.begin();
    if (a[i] < a[j])
        cout << i + 1 << '\n';
    else
        cout << j + 1 << '\n';
    return 0;
}