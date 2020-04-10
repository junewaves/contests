#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, prev, curr, start;
    cin >> n >> m >> k >> prev;
    start = prev;
    vector<int> q;
    q.reserve(n - 1);
    for (int i = 1; i < n; i++) {
        cin >> curr;
        q.push_back(curr - prev);
        prev = curr;
    }
    int sum = curr - start + k;
    sort(q.begin(), q.end(), greater<int>());
    for (int i = 0; i < k - 1; i++) {
        sum -= q[i];
    }
    cout << sum << '\n';
    return 0;
}