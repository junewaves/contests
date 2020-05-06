#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    unordered_map<char, int> hashing;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        hashing[c] += 1;
    }
    if ((int)hashing.size() != k)
        cout << 0 << endl;
    else {
        int lo = hashing['A'];
        for (auto& e : hashing) {
            lo = min(e.second, lo);
        }
        cout << lo * k << endl;
    }
    return 0;
}
