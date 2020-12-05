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


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    constexpr int INF = 1e9 + 5;
    for (int z = 1; z <= n; z++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        for (int i = 0; i < m; i++) {
            a[i]++;
        }
        int sl = (l > 0 ? *min_element(a.begin(), a.begin() + l) : INF);
        int sr = (r + 1 < m ? *min_element(a.begin() + r + 1, a.end()) : INF);
        int ans = min(sl, sr);
        cout << (ans >= INF ? -1 : ans) << '\n';
        int offset = 1, base = l > 0 ? a[l - 1] : INF;
        for (int i = l; i <= r; i++) {
            a[i] = base + offset;
            offset++;
        }
        debug(a);
    }
    return 0;
}