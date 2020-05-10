#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int mxN = 2e5 + 5;
int n, A[mxN], vis[mxN];
ll k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    int s = 1;
    while (vis[s] < 2) {
        vis[s]++;
        s = A[s];
    }
    ll a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1)
            a++;
        else if (vis[i] == 2)
            b++;
    }

    ll moves = (k - a) % b + a;

    if (k < a)
        moves = k;

    s = 1;
    for (ll i = 0; i < moves; i++) {
        s = A[s];
    }
    cout << s;
    /*
        cout << endl;
        cout << moves << endl;
        for (int i = 1; i <= n; i++)
            cout << vis[i] << " ";
        cout << endl;*/
}
