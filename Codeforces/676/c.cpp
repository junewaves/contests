#include <bits/stdc++.h>
using namespace std;

// abcdef
// babcdef
// babcdefedcba
inline bool is_palin(const string& s) {
    int n =(int)s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    if (is_palin(s)) {
        cout << "0\n";
        return 0;
    }
    cout << "3\n";
    cout << "L 2\n";
    cout << "R 2\n";
    int n = s.size();
    cout << "R " << 2 * n - 1 << "\n";
    return 0;
}

