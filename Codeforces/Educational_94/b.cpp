#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef _LOCAL_DEBUG
#define en_if(x) typename enable_if<sizeof(check<T>(0)) x 1, void>::type
#define PL bool b = 0; for(auto& x : v) { if(b) put(", "); b = 1; put(x); }
namespace dbg {
template<class T> char check(...); 
template<class T> auto check(T* x) -> decltype(cerr << *x, 0); 
template<class F, class S> 
void put(pair<F, S>& v) { cerr << "(" << v.first << ", " << v.second << ")"; }
template<class T> en_if(!=) put(T& v) { cerr << v; }
template<class T> en_if(==) put(T& v) { cerr << "["; PL; cerr << "]"; }
void out() { cerr << endl; }
template<class H, class... T> 
void out(H h, T... t) { put(h); if(sizeof...(t)) cerr << ", "; out(t...); }
static auto bv = []{ cerr << boolalpha; return true; }();
}
#define debug(...) \
    cerr << "debug(" << #__VA_ARGS__ << "): ", dbg::out(__VA_ARGS__)
#else
#define debug(...)
#endif


void solve() {
    ll p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    if (s > w) {
        swap(cs, cw);
        swap(s, w);
    }
    ll ans = 0; 
    for (int i = 0; i <= cs && i * s <= p; i++) {
        ll take1 = i + min(cw, (p - s * i) / w);
        ll x = cs - i, y = cw - take1 + i;
        ll take2 = min(x, f / s);
        ll left = f - take2 * s;
        take2 += min(y, left / w);
        ans = max(ans, take1 + take2);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}