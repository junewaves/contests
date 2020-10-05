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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    using mint = modnum<int(1e9) + 7>;
    string s;
    cin >> s;
    int n = s.size();
    mint ans = 0;
    mint front = mint(n) * (n - 1) / 2;
    mint back = 0;
    mint ten = 1;
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        ans += (front + back) * (s[i] - '0');
        
        front = front * 10 * (i - 1) / (i + 1);
        back += ten * (j + 1);
        ten *= 10;
    }
    cout << ans << '\n';
    return 0;
}