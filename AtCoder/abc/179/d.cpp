#include <bits/stdc++.h>
using namespace std;

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
using mint = modnum<998244353>;

struct segTree {
    int N;
    vector<mint> val;
    segTree(int _n) : N(_n) {
        // initialize array
        val.resize(2 * N);
        // build tree
        for (int i = N - 1; i > 0; i--)
            val[i] = val[i << 1] + val[i << 1 | 1];
    }
    void update(int i, mint d) {
        // this is assignment update
        for (val[i += N] = d; i >>= 1;) {
            val[i] = val[i << 1] + val[i << 1 | 1];
        }
    }
    mint query(int l, int r) {
        // query sum of range [l, r)
        mint res = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1)
                res += val[l++];
            if (r & 1)
                res += val[--r];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> seg(k);
    for (int i = 0; i < k; i++)
        cin >> seg[i][0] >> seg[i][1];
    segTree st(n);
    st.update(0, 1);
    for (int i = 1; i < n; i++) {
        mint dp = 0;
        for (const auto& s : seg) {
            if (i - s[0] >= 0) {
                int r = i - s[0] + 1;
                int l = max(i - s[1], 0);
                // cout << l << ' ' << r << '\n';
                dp += st.query(l, r);
            }
        }
        st.update(i, dp);
    }
    cout << st.query(n - 1, n) << '\n';
    return 0;
}