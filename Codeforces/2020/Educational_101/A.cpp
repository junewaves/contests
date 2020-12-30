#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        if (s.size() % 2 || s.front() == ')' || s.back() == '(')
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}