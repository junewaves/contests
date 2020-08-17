#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

constexpr int mod = 1e9 + 7;
int N, W;
vector<ll> L, H;
void process_input() {
    L.clear();
    H.clear();
    int K;
    vector<ll> tupl(4), tuph(4);
    cin >> N >> K >> W;
    L.resize(N);
    H.resize(N);
    for (int i = 0; i < K; i++)
        cin >> L[i];
    for (int i = 0; i < 4; i++)
        cin >> tupl[i];
    for (int i = 0; i < K; i++)
        cin >> H[i];
    for (int i = 0; i < 4; i++)
        cin >> tuph[i];
    for (int i = K; i < N; i++)
        L[i] = (tupl[0] * L[i - 2] + tupl[1] * L[i - 1] + tupl[2]) % tupl[3] + 1;
    for (int i = K; i < N; i++)
        H[i] = (tuph[0] * H[i - 2] + tuph[1] * H[i - 1] + tuph[2]) % tuph[3] + 1;
}

void solve() {
    process_input();
    vector<ll> P(N);
    P[0] = 2LL * (H[0] + W) % mod;
    ll ans = P[0];
    // int end_point = L[0] + W;
    for (int i = 1; i < N; i++) {
        P[i] = (P[i - 1] + 2LL * (H[i] + W)) % mod;
        if (L[i] <= L[i - 1] + W) {
            ll mx = H[i - 1], j = i - 1;
            ll width = L[i - 1] + W - L[i];
            while (j >= 0 && L[j] + W >= L[i]) {
                mx = max(mx, H[j]);
                j--;
            }
            P[i] = (P[i] - 2LL * (width + min(H[i], mx))) % mod;
            if (P[i] < 0)
                P[i] += mod;
        }
        ans = ans * P[i] % mod;
        // cout << P[i] << ' ';
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