#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef _LOCAL_DEBUG
#define en_if typename enable_if<sizeof x<T>(0) == 4, ostream&>::type
namespace dbg {
template<class T> char x(...); 
template<class T> auto x(T* v) -> decltype(v->size(), 0); 
template<class T> auto x(T* v) -> decltype(v->c_str(), "");
template<class T> en_if operator<<(ostream& os, const T& v) { 
    os << "["; const char* sep = ""; 
    for(const auto& x : v) os << sep << x, sep = ", ";
    return os << "]";
}
template<class F, class S> 
ostream& operator<<(ostream& os, const pair<F, S>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template<class T> 
void print(const char* n, T e) { cerr << "[" << n << ": " << e << "]\n"; }
template<class Head, class... Tail> 
void print(const char* n, Head h, Tail... t) {
    cerr << "["; while(*n != ',') cerr << *n++; cerr << ": " << h << "] ";
    print(n + 2, t...); 
}}
#define debug(...) dbg::print(#__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

template<int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;
    int v;
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) {
        if (v < 0)
            v += MOD;
    }
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& out, const modnum& n) {
        return out << int(n);
    }
    friend istream& operator>>(istream& in, modnum& n) {
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator-() const { return neg(); }
    modnum operator+() const { return modnum(*this); }
    modnum& operator++() {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator--() {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    modnum& operator+=(const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator-=(const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator*=(const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum& operator/=(const modnum& o) { return *this *= o.inv(); }

    friend modnum operator++(modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator--(modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator+(const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

constexpr int mxN = 3e5 + 2;
using mint = modnum<998244353>;

mint Fac[mxN];
mint Inv[mxN];

mint choose(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return Fac[n] * Inv[r] * Inv[n - r];
}

void init() {
    Fac[0] = 1;
    for (int i = 1; i < mxN; i++)
        Fac[i] = Fac[i - 1] * i;
    Inv[mxN - 1] = Fac[mxN - 1].inv();
    for (int i = mxN - 1; i > 0; i--)
        Inv[i - 1] = Inv[i] * i;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> p(n), r(m);
    for (int i = 0; i < n; i++)
        cin >> p[i][0] >> p[i][1];
    for (int i = 0; i < m; i++)
        cin >> r[i][0] >> r[i][1];
    vector<int> cnt(n + 2);
    for (auto& v : p) {
        cnt[v[0]]++;
        cnt[v[1] + 1]--;
    }
    // count of people the can be selected into a team of i members
    for (int i = 0; i < n + 1; i++)
        cnt[i + 1] += cnt[i];
    vector<vector<mint>> dp(2 * m + 1, vector<mint>(n + 1));
    // iterate over possible number of people in team
    for (int i = 1; i <= n; i++) {
        // number of people can't be choosed because of some edges
        for (int j = 0; j <= 2 * m; j++) {
            // compute as prefix sum
            dp[j][i] = dp[j][i - 1] + choose(cnt[i] - j, i - j);
        }
    }
    // debug(cnt, dp);
    mint ans = 0;
    // inclusion-exclusion
    // check every possible combination of edge selection
    for (int mask = 0; mask < (1 << m); mask++) {
        mint sign = 1;
        set<int> used;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                sign *= mint(-1);
                used.insert(r[i][0] - 1);
                used.insert(r[i][1] - 1);
            }
        }
        int L = 1, R = n;
        for (auto x : used) {
            L = max(L, p[x][0]);
            R = min(R, p[x][1]);
        }
        if (R < L) continue;
        // debug(dp[used.size()][R], dp[used.size()][L]);
        ans += sign * (dp[used.size()][R] - dp[used.size()][L - 1]);
    }
    cout << ans << '\n';
    return 0;
}