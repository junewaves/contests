#include <bits/stdc++.h>
using namespace std;

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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> y[i];
        sort(x.begin(), x.end());
        int ans = 0;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            int j = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin();
            dp[i] = j - i;
            ans = max(ans, j - i + (j < n ? dp[j] : 0));
            if (i + 1 < n)
                dp[i] = max(dp[i], dp[i + 1]);
        }
        debug(dp);
        cout << ans << '\n';
    }
    return 0;
}