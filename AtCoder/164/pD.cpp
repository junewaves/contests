#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
char s[200005];
int modulo(int a, int b) {
    if (b == 0)
        return 1;
    const int m = 2019;
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1)
            x = x * y % m;
        y = y * y % m;
        b /= 2;
    }
    return x % m;
}
int main() {
    scanf("%s", s);
    int n = strlen(s);
    if (n < 5) {
        puts("0");
        return 0;
    }
    unordered_map<int, int> m;
    int sum = 0;
    ll cnt = 0;
    m[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        sum = (sum + (s[i] - '0') * modulo(10, n - 1 - i)) % 2019;
        if (m.find(sum) != m.end())
            cnt += m[sum];
        m[sum]++;
    }
    printf("%lld\n", cnt);
}
