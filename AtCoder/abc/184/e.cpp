#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (string& row : A) cin >> row;
    vector<pair<int, int>> teleport[26];
    vector<vector<int>> dist(H, vector<int>(W, int(1e9)));
    int si, sj, ei, ej;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            switch (A[i][j]) {
            case 'S':
                si = i, sj = j; break;
            case 'G':
                ei = i, ej = j; break;
            case '.':
                break;
            case '#':
                dist[i][j] = int(-1e9); break;
            default:
                assert('a' <= A[i][j] && A[i][j] <= 'z');
                teleport[A[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }
    const pair<int, int> directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    priority_queue<pair<int, pair<int, int>>> pq;
    dist[si][sj] = 0;
    pq.push({0, {si, sj}});
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int d = -t.first;
        auto [i, j] = t.second;
        if (d != dist[i][j]) continue;
        for (auto [di, dj] : directions) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && dist[ni][nj] > d + 1) {
                dist[ni][nj] = d + 1;
                pq.push({-(d + 1), {ni, nj}});
            }
        }
        if ('a' <= A[i][j] && A[i][j] <= 'z') {
            for (auto [ni, nj] : teleport[A[i][j] - 'a']) {
                if (dist[ni][nj] > d + 1) {
                    dist[ni][nj] = d + 1;
                    pq.push({-(d + 1), {ni, nj}});
                }
            }
            teleport[A[i][j] - 'a'].clear(); // we use each teleport at most once
        }
    }
    cout << (dist[ei][ej] < int(1e9) ? dist[ei][ej] : -1) << '\n';
    return 0;
}