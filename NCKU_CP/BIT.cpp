#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
constexpr const int MAXN = 1e5 + 5;
int bit[MAXN];  // binary indexed tree
int val[MAXN];  // array to store values
int n;

void add(int i, int d) {
    // update interval by adding O(logN)
    while (i < n) {
        bit[i] += d;
        i += lowbit(i);
    }
}

int sum(int i) {
    // calc sum from start to i O(logN)
    int res = 0;
    while (i) {
        res += bit[i];
        i -= lowbit(i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
