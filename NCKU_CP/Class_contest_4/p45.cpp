#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K, cnt = 0;
bool visited[1000005];
void climb(int i) {
    if (visited[i])
        return;
    visited[i] = true;
    cnt++;
    climb(i >> 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    visited[0] = visited[1] = true;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> K;
        climb(K);
    }
    cout << cnt << '\n';
}
