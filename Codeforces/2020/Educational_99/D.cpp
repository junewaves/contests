#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_DEBUG
#include "../prettyprint.hpp"  // https://louisdx.github.io/cxx-prettyprint/
template<class T>
void dbg_print(const char* name, T last) {
    cerr << " [" << name << ": " << last << "]\n";
}
template<class H, class... T>
void dbg_print(const char* name, H head, T... tail) {
    const char* comma = strchr(name + 1, ',');
    (cerr << " [").write(name, comma - name) << ": " << head << "] ";
    dbg_print(comma + 2, tail...);
}
#define debug(...) dbg_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        auto get_first = [&] {
            for (int i = 0; i < n; i++) 
                if (a[i] > x) 
                    return i;
            return -1;
        };
        int cnt = 0;
        while (!is_sorted(a.begin(), a.end())) {
            int i = get_first();
            if (i < 0)  break;
            swap(a[i], x);
            cnt++;
        }
        cout << (is_sorted(a.begin(), a.end()) ? cnt : -1) << '\n';
    }
    return 0;
}


/*
1
 7 1
 1 3 2 4 3 5 4

*/