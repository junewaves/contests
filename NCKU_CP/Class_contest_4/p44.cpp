#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;

int my_heap[1000005];

void climb(int i) {
    if (i == 0)
        return;
    if (my_heap[i] == 1)
        return;

    my_heap[i] = 1;
    climb(i / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int ans = 0;
    int I;
    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> I;
        if (I <= N)
            climb(I);
    }

    for (int i = 0; i <= N; i++) {
        ans += my_heap[i];
    }
    cout << ans - 1 << '\n';
}
