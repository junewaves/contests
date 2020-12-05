#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
        cnt += c == 'R';
    cout << (cnt == 2 && s[1] == 'S' ? 1 : cnt);
    
    return 0;
}