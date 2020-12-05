#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int n, x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < 2e6; i++) {
        x = (x * 10 + 7) % n;
        if (x == 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
/*
*/