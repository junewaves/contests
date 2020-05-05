#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> k;
/* solution 1: set O(KlogN)
set<int> alive;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    k.resize(n, 0);
    for (int i = 0; i < n; i++)
        alive.insert(i);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        auto it = alive.lower_bound(l);
        vector<int> toErase;
        while (it != alive.end()) {
            int c = *it;
            if (c > r)
                break;
            if (c != x)
                toErase.push_back(c);
            it++;
        }
        for (int c : toErase) {
            alive.erase(c);
            k[c] = x + 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << k[i] << " ";
    cout << '\n';
}*/
// solution 2: O(K);
vector<int> Next;
int getNext(int v) {
    if (v >= n)
        return (int)1e9;
    if (Next[v] == v)
        return v;
    return Next[v] = getNext(Next[v]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    k.resize(n, 0);
    Next.resize(n, 0);
    for (int i = 1; i < n; i++)
        Next[i] = i;
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        int c = getNext(l);
        while (c <= r) {
            if (c == x) {  // winner
                c++;
            } else {
                k[c] = x + 1;
                Next[c] = c + 1;
            }
            c = getNext(c);
        }
    }
    for (int i : k)
        cout << i << " ";
    cout << endl;
}
