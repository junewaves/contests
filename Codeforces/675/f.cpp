#include <bits/stdc++.h>
using namespace std;

// #ifdef _LOCAL_DEBUG
// #include "prettyprint.hpp"
// #endif

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
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    modnum pow(ll k) const {
        modnum res = 1, x = *this;
        while (k) {
            if (k & 1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }

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

using mint = modnum<int(1e9) + 7>; // 998244353

struct node {
    vector<pair<int, int>> small;
    vector<pair<int, int>> big;
    vector<mint> prefix;
    // friend ostream& operator<<(ostream& os, node& n) {
    //     os << "Node: {\n";
    //     os << "  small: " << n.small << "\n";
    //     os << "    big: " << n.big << "\n";
    //     os << " preifx: " << n.prefix << "\n";
    //     return os << "}\n";
    // }
};


struct segtree {
    using node_vec = vector<pair<int, int>>;
    int n;
    vector<node> t;
    segtree(vector<node>& a) : n(int(a.size())), t(2 * a.size()) {
        for (int i = 0; i < n; i++) {
            t[i + n] = move(a[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            int lc = i << 1, rc = lc | 1;
            t[i].small = op(t[lc].small, t[rc].small);
            merge(t[lc].big.begin(), t[lc].big.end(), 
                  t[rc].big.begin(), t[rc].big.end(),
                  back_inserter(t[i].big));
            mint prod = 1;
            for (auto& p : t[i].big) {
                prod *= p.second;
                t[i].prefix.push_back(prod);
            }
        }
    }
    inline node_vec op(const node_vec& a, const node_vec& b) {
        node_vec res;
        res.reserve(a.size() + b.size());
        auto i = a.begin(), j = b.begin();
        while (i != a.end() && j != b.end()) {
            if (i->first < j->first) {
                res.push_back(*i);
                i++;
            } else if (i->first > j->first) {
                res.push_back(*j);
                j++;
            } else {
                res.push_back(i->second > j->second ? *i : *j);
                i++, j++;
            }
        }
        while (i != a.end()) res.push_back(*i), i++;
        while (j != b.end()) res.push_back(*j), j++;
        return res;
    }
    inline int search(const node_vec& vec, int target) {
        return lower_bound(vec.begin(), vec.end(), make_pair(target, 0)) - vec.begin();
    }
    mint query(int l, int r) {
        int l_save = l;
        node_vec pf;
        mint ret = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                pf = op(pf, t[l].small);
                int pos = search(t[l].big, l_save);
                if (pos) { 
                    ret *= t[l].prefix[pos - 1];
                }
                l++;
            }
            if (r & 1) {
                --r;
                pf = op(pf, t[r].small);
                int pos = search(t[r].big, l_save);
                if (pos) { 
                    ret *= t[r].prefix[pos - 1];
                }
            }
        }
        for (const auto& [f, p] : pf) {
            ret *= mint(f).pow(p);
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int mxn = int(2e5);
    constexpr int small = 447; // sqrt(mxn)
    vector<int> pr(mxn + 1);
    for (int i = 2; i <= mxn; i += 1 + (i & 1)) {
        if (!pr[i]) {
            for (int j = i; j <= mxn; j += i) {
                pr[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    vector<node> a(n); // small prime factors
    unordered_map<int, int> mp; // last index of each big primes
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        map<int, int> cnt;
        while (tmp > 1) {
            int p = pr[tmp];
            if (p < small) {
                cnt[p]++;
            } else {
                auto it = mp.find(p);
                int prv = it == mp.end() ? -1 : it->second;
                a[i].big.emplace_back(prv, p);
                a[i].prefix.push_back(p);
                mp[p] = i;
            }
            tmp /= p;
        }
        a[i].small = vector<pair<int, int>>(cnt.begin(), cnt.end());
    }
    segtree st(a);
    // for (auto t : st.t) {
    //     cout << t << '\n';
    // }
    int q, last = 0;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (last + l) % n;
        r = (last + r) % n;
        if (l > r) swap(l, r);
        // cout << l << ' ' << r + 1 << '\n';
        mint ans = st.query(l, r + 1);
        cout << ans << '\n';
        last = int(ans);
    }
    return 0;
}