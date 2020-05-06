#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;
#include "lib0043.h"
int a = 1, b = 2;  // a small, b big
int cmp(int t, int i) {
    if (t == 0) {
        if (Collision(a, i)) {
            a = i;
            return 1;
        } else if (Collision(i, b)) {
            b = i;
            return 2;
        }
    } else {
        if (Collision(i, b)) {
            b = i;
            return 2;
        } else if (Collision(a, i)) {
            a = i;
            return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    srand(time(0));
    MagicBalls(&n);
    // a=min, b=max
    if (Collision(a, b)) {
        int t = a;
        a = b;
        b = t;
    }
    int last = 0;
    for (int i = 3; i < n; i += 2) {
        if (Collision(i, i + 1)) {
            if (Collision(i, b))
                b = i;
            if (Collision(a, i + 1))
                a = i + 1;
        } else {
            if (Collision(i + 1, b))
                b = i + 1;
            if (Collision(a, i))
                a = i;
        }
    }
    if (n % 2 == 1) {
        if (Collision(n, b))
            b = n;
        else if (Collision(a, n))
            a = n;
    }
    Choose(a, b);
}
