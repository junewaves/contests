#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (s.size() <= n) {
        cout << s;
    } else {
        cout << s.substr(0, n) << "...";
    }
}
