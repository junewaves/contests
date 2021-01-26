#include <bits/stdc++.h>
using namespace std;

using min_heap = priority_queue<int, vector<int>, greater<int>>;
constexpr int mod = 1e9 + 7;
constexpr int mxn = 1001;
int choose[mxn][mxn];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    choose[0][0] = 1;
    for (int i = 1; i < mxn; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            if (choose[i][j] >= mod)
                choose[i][j] -= mod;
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> f(n);
        for (int& it : f)
            cin >> it;
        min_heap heap(f.begin(), f.begin() + k);
        for (int i = k; i < n; i++) {
            if (f[i] > heap.top()) {
                heap.pop();
                heap.push(f[i]);
            }
        }
        int th = heap.top();
        int N = count(f.begin(), f.end(), th);
        k -= count_if(f.begin(), f.end(), [&](int v) { return v > th; });
        cout << choose[N][k] << '\n';
    }
    return 0;
}
