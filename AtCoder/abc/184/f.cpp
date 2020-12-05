#include <bits/stdc++.h>
using namespace std;

vector<int> split(vector<int> A, int T) {
    int n = A.size();
    vector<int> res{0};
    res.reserve(1 << n);
    for (int x = 0; x < n; x++) {
        int L = res.size();
        for (int i = 0; i < L; i++)
            if (res[i] + A[x] <= T)
                res.push_back(res[i] + A[x]);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int &a : A) cin >> a;
    int ans = 0;
    if (N <= 20) {
        auto B = split(A, T);
        ans = *--upper_bound(B.begin(), B.end(), T);
    } else {
        int mid = N / 2;
        auto B = split(vector<int>(A.begin(), A.begin() + mid), T);
        auto C = split(vector<int>(A.begin() + mid, A.end()), T);
        for (int x : B) {
            if (x > T) break;
            ans = max(ans, x + *--upper_bound(C.begin(), C.end(), T - x));
        }
    }
    cout << ans << '\n';
    return 0;
}