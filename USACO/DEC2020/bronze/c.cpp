#include <bits/stdc++.h>
using namespace std;

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int inf = 1e9 + 5;
    int N;
    cin >> N;
    vector<bool> dir(N);
    vector<int> x(N), y(N), stop_at(N, inf);
    for (int i = 0; i < N; i++) {
        char d;
        cin >> d;
        dir[i] = d == 'N';
        cin >> x[i] >> y[i];
    }
    min_pq<tuple<int, int, int, int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (dir[i] == dir[j]) {
                if (dir[i] && x[i] == x[j]) { // to north
                    if (y[j] > y[i])
                        pq.push(make_tuple(y[j] - y[i], 0, i, j));
                    else if (y[i] > y[j])
                        pq.push(make_tuple(y[i] - y[j], 0, j, i));
                } else if (!dir[i] && y[i] == y[j]) { // to east
                    if (x[j] > x[i])
                        pq.push(make_tuple(x[j] - x[i], 0, i, j));
                    else if (x[i] > x[j])
                        pq.push(make_tuple(x[i] - x[j], 0, j, i));
                }
            } else {
                int n, e;
                if (dir[i])
                    n = i, e = j;
                else 
                    n = j, e = i;
                if (y[e] >= y[n] && x[n] >= x[e]) {
                    int tn = y[e] - y[n], te = x[n] - x[e];
                    if (te > tn)
                        pq.push(make_tuple(te, tn, e, n));
                    else if (tn > te)
                        pq.push(make_tuple(tn, te, n, e));
                }
            }
        }
    }
    while (pq.size()) {
        int ti, tj, i, j;
        tie(ti, tj, i, j) = pq.top();
        pq.pop();
        if (stop_at[i] >= inf && stop_at[j] > tj)
            stop_at[i] = ti;
    }
    for (int i = 0; i < N; i++) {
        if (stop_at[i] >= inf)
            cout << "Infinity\n";
        else
            cout << stop_at[i] << '\n';
    }
    return 0;
}