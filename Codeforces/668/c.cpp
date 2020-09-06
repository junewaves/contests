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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto f = [](char c) -> int { return c == '?' ? 2 : c - '0'; };
    string p(k, '?');
    for (int i = 0; i < k; i++) {
        array<int, 3> cnt{};
        for (int j = i; j < n; j += k) {
            cnt[f(s[j])]++;
        }
        if (cnt[0] != 0) {
            if (cnt[1] != 0) {
                cout << "NO\n";
                return;
            }
            p[i] = '0';
        } else if (cnt[1] != 0) {
            p[i] = '1';
        }
    }
    array<int, 3> cnt{};
    for (char c : p) {
        cnt[f(c)]++;
    }
    // debug(p, s, cnt);
    if (abs(cnt[0] - cnt[1]) > cnt[2]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}