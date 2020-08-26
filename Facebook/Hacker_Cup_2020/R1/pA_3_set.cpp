#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int mod = 1e9 + 7;
constexpr ll inf = 1e18;
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
    set<array<ll, 3>> seg;
    seg.insert({-inf, -inf, 0});
    seg.insert({-inf, L[0], 0});
    seg.insert({L[0], L[0] + W[0], H[0]});
    seg.insert({L[0] + W[0], inf, 0});
    seg.insert({inf, inf, 0});
    for (int i = 1; i < N; i++) {
        auto x = --seg.lower_bound({L[i], inf, inf});
        auto y = --seg.lower_bound({L[i] + W[i], inf, inf});
        if ((*x)[0] == L[i])
            x--;
        if (x == y) {
            auto vx = *x;
            p1 = (p0 + 2LL * (H[i] - vx[2])) % mod;
            if (vx[2] == 0)
                p1 = (p1 + 2LL * W[i]) % mod;
            array<ll, 3> left{vx[0], L[i], vx[2]};
            array<ll, 3> mid{L[i], L[i] + W[i], H[i]};
            array<ll, 3> right{L[i] + W[i], vx[1], vx[2]};
            seg.erase(x);
            if (left[1] > left[0])
                seg.insert(left);
            seg.insert(mid);
            if (right[1] > right[0])
                seg.insert(right);
        } else {
            auto vx = *x, vy = *y;
            y++;
            ll p2 = 0;
            for (auto it = x; it != y; it++) {
                auto now = *it;
                if (now[2] > 0) {
                    auto prv = *prev(it), nxt = *next(it);
                    p2 += 2LL * (now[1] - now[0]);
                    if (now[2] > prv[2])
                        p2 += now[2] - prv[2];
                    if (now[2] > nxt[2])
                        p2 += now[2] - nxt[2];
                    p2 %= mod;
                }
            }
            array<ll, 3> left{vx[0], L[i], vx[2]};
            array<ll, 3> mid{L[i], L[i] + W[i], H[i]};
            array<ll, 3> right{L[i] + W[i], vy[1], vy[2]};
            seg.erase(x, y);
            if (left[1] > left[0])
                seg.insert(left);
            else 
                left = mid;
            seg.insert(mid);
            if (right[1] > right[0])
                seg.insert(right);
            else 
                right = mid;
            auto l = seg.find(left);
            auto r = ++seg.find(right);
            ll p3 = 0;
            for (auto it = l; it != r; it++) {
                auto now = *it;
                if (now[2] > 0) {
                    auto prv = *prev(it), nxt = *next(it);
                    p3 += 2LL * (now[1] - now[0]);
                    if (now[2] > prv[2])
                        p3 += now[2] - prv[2];
                    if (now[2] > nxt[2])
                        p3 += now[2] - nxt[2];
                    p3 %= mod;
                }
            }
            p1 = ((p0 - p2 + p3) % mod + mod) % mod;
        }
        ans = ans * p1 % mod;
        p0 = p1;
    }
    cout << ans << endl;
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