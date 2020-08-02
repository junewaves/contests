#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int n;
char s[200005];

int main() {
    scanf("%d%s", &n, s);
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
        if (s[r] == 'W')
            r--;
        if (s[l] == 'R') {
            l++;
        } else {
            while (l < r && s[r] == 'W')
                r--;
            if (l < r)
                swap(s[l], s[r]), ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
// wwrrrrr