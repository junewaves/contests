#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        int r = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i])
                r++;
            else if (s1[i] < s2[i])
                b++;
        }
        if (r == b)
            cout << "EQUAL\n";
        else if (r > b)
            cout << "RED\n";
        else
            cout << "BLUE\n";
    }
    return 0;
}