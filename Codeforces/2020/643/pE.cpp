#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, A, R, M;
    cin >> N >> A >> R >> M;
    M = min(M, A + R);
    vector<ll> t(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> t[i];
    sort(t.begin() + 1, t.end());
    vector<ll> u(t.begin() + 1, t.end());
    u.resize(unique(u.begin(), u.end()) - u.begin());
    vector<ll> pre(N + 1);
    for (int i = 1; i <= N; i++)
        pre[i] = pre[i - 1] + t[i];
    t[0] = -1;
    // additional points that need to be checked
    // is where the relation between P and Q changed
    ll break_point = (pre[N] - pre[0]) / N;
    u.push_back(break_point);  // floor of break point
    u.push_back(break_point + 1);  // ceil of bp (if not exact division)
    ll lb, ub, P, Q, cost, ans = LLONG_MAX;
    for (ll h : u) {
        lb = lower_bound(t.begin(), t.end(), h) - t.begin() - 1;
        ub = upper_bound(t.begin(), t.end(), h) - t.begin() - 1;
        P = lb * h - pre[lb];
        Q = pre[N] - pre[ub] - (N - ub) * h;
        if (Q > P) {
            cost = R * (Q - P) + M * P;
        } else {
            cost = A * (P - Q) + M * Q;
        }
        ans = min(ans, cost);
    }
    cout << ans;
    return 0;
}
