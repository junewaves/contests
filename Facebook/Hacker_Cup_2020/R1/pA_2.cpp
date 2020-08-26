#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

constexpr int mod = 1e9 + 7;
int N;
vector<ll> L, W, H;
void process_input() {
    L.clear();
    W.clear();
    H.clear();
    int K;
    vector<ll> tupl(4), tupw(4), tuph(4);
    cin >> N >> K;
    L.resize(N);
    W.resize(N);
    H.resize(N);
    for (int i = 0; i < K; i++)
        cin >> L[i];
    for (int i = 0; i < 4; i++)
        cin >> tupl[i];
    for (int i = 0; i < K; i++)
        cin >> W[i];
    for (int i = 0; i < 4; i++)
        cin >> tupw[i];
    for (int i = 0; i < K; i++)
        cin >> H[i];
    for (int i = 0; i < 4; i++)
        cin >> tuph[i];
    for (int i = K; i < N; i++)
        L[i] =
            (tupl[0] * L[i - 2] + tupl[1] * L[i - 1] + tupl[2]) % tupl[3] + 1;
    for (int i = K; i < N; i++)
        W[i] =
            (tupw[0] * W[i - 2] + tupw[1] * W[i - 1] + tupw[2]) % tupw[3] + 1;
    for (int i = K; i < N; i++)
        H[i] =
            (tuph[0] * H[i - 2] + tuph[1] * H[i - 1] + tuph[2]) % tuph[3] + 1;
}

void solve() {
    process_input();
    ll p0 = 2LL * (H[0] + W[0]) % mod, p1 = 0;
    ll ans = p0;
    vector<pair<ll, ll>> seg;
    seg.emplace_back(LLONG_MIN, LLONG_MIN);
    seg.emplace_back(L[0], L[0] + W[0]);
    seg.emplace_back(LLONG_MAX, LLONG_MAX);
    for (int i = 1; i < N; i++) {
        pair<ll, ll> pi = {L[i], L[i] + W[i]};
        auto x = --lower_bound(seg.begin(), seg.end(), pi,
            [](const auto& a, const auto& b) { return a.first < b.first; });
        auto y = upper_bound(seg.begin(), seg.end(), pi,
            [](const auto& a, const auto& b) { return a.second < b.second; });
        p1 = p0;
        if (y - x == 1 && x->second < L[i] && L[i] + W[i] < y->first) {
            p1 = (p0 + 2LL * (H[i] + W[i])) % mod;
            seg.insert(y, pi);
        } else {
            if (x->second < L[i]) {
                x++;
                p1 += 2LL * (x->first - L[i]);
            }
            if (y->first > L[i] + W[i]) {
                y--;
                p1 += 2LL * (L[i] + W[i] - y->second);
            }
            p1 %= mod;
            for (auto it = x; it != y; it++) {
                auto it2 = next(it);
                p1 = (p1 + 2LL * (it2->first - it->second - H[i])) % mod;
                if (p1 < 0)
                    p1 += mod;
            }
            *x = make_pair(min(x->first, L[i]), max(y->second, L[i] + W[i]));
            if (x < y)
                seg.erase(x + 1, y + 1);
        }
        ans = ans * p1 % mod;
        p0 = p1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int cn = 1; cn <= tt; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}