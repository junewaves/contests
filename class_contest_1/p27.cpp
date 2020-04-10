#include <bits/stdc++.h>
using namespace std;
struct edge {
    int node_id, relation;
};
typedef unordered_map<int, vector<edge>> AdjencencyList;
int n, m, t, a, b;
AdjencencyList graph;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;  // n = number of people, m = number of actions
    while (m--) {
        cin >> t >> a >> b;
        switch (t) {
        default:
        case 1:
            // set as friend
            break;
        case 2:
            // set as enemy
            break;
        case 3:
            // ask for relation
            break;
        }
    }
}