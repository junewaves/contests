#include <bits/stdc++.h>
using namespace std;

template<class T, const T& (*F)(const T&, const T&) = max>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) {
        int N = V.size(), tmp = 1, depth = 1;
        while (tmp < N) {
            tmp *= 2;
            depth++;
        }
        jmp.assign(depth, V);
        for (int i = 0; i < depth - 1; i++)
            for (int j = 0; j < N; j++)
                jmp[i + 1][j] = F(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
    }

    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return F(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> seen(n + 1);
        int rest = n;
        for (int &it : a) {
            cin >> it;
            if (!seen[it]) {
                rest--;
                seen[it] = true;
            }
        }
        RMQ<int, min> q(a);
        vector<bool> ok(n);
        if (rest == 0)
            ok[n - 1] = true;
        int L = 0, R = n;
        for (int k = 1; k < n; k++) {
            int left = q.query(L, R - 1);
            int right = q.query(L + 1, R);
            if (min(left, right) == k)
                ok[k - 1] = true;
            if (left == k && right > k)
                L++;
            else if (left > k && right == k)
                R--;
            else
                break;
        }
        for (int i = n - 1; i >= 0; i--)
            cout << (ok[i] ? '1' : '0');
        cout << '\n';
    }
    return 0;
}
