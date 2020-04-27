#include <iostream>
#include <unordered_map>
#include <vector>
// #define int unsigned short
#define NO_GROUP -1
#define MAX_N 100000
using namespace std;

int n, m, t;
int a, b;
unordered_map<int, int> enemies;
int group[MAX_N];
// vector<int> group;

int findGroup(int v) {
    if (group[v] == NO_GROUP)
        return NO_GROUP;
    else if (group[v] == v)
        return v;
    else
        return group[v] = findGroup(group[v]);
}
void setGroup(int v, int newGroup) {
    int lead = findGroup(v);
    if (lead == NO_GROUP)
        group[v] = newGroup;
    else
        group[lead] = newGroup;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // initialization
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        group[i] = NO_GROUP;
    }
    // group.resize(n + 1, NO_GROUP);
    while (m--) {
        cin >> t >> a >> b;
        int ga = findGroup(a), gb = findGroup(b);
        if (t == 1) {  // set friends
            if (ga == NO_GROUP) {
                if (gb == NO_GROUP) {
                    // create new group
                    setGroup(a, a);
                    setGroup(b, a);
                } else {
                    // add a to b's group
                    setGroup(a, gb);
                }
            } else if (gb == NO_GROUP) {
                // add b to a's group
                setGroup(b, ga);
            } else if (ga != gb) {
                // if a, b are in different groups
                bool aHasEnemy = enemies.find(ga) != enemies.end(),
                     bHasEnemy = enemies.find(gb) != enemies.end();
                if (aHasEnemy && bHasEnemy) {
                    // two groups are enemies
                    if (enemies[ga] == gb)
                        cout << "nani\n";
                    else {
                        int aEnemy = enemies[ga], bEnemy = enemies[gb];
                        // combine group a and group b
                        setGroup(gb, ga);
                        // combine their enemies
                        setGroup(aEnemy, bEnemy);
                        // change enemy relation
                        enemies[ga] = bEnemy;
                        enemies[bEnemy] = ga;
                    }
                } else if (bHasEnemy) {
                    // merge a into b
                    setGroup(ga, gb);
                } else {
                    // merge b into a
                    setGroup(gb, ga);
                }
            }
        } else if (t == 2) {  // set enemies
            if (ga == NO_GROUP) {
                setGroup(a, a);
                ga = a;
            }
            if (gb == NO_GROUP) {
                setGroup(b, b);
                gb = b;
            }
            if (ga != gb) {
                bool aHasEnemy = enemies.find(ga) != enemies.end(),
                     bHasEnemy = enemies.find(gb) != enemies.end();
                if (aHasEnemy && bHasEnemy) {
                    if (enemies[ga] != gb) {
                        int aEnemy = enemies[ga], bEnemy = enemies[gb];
                        setGroup(gb, aEnemy);
                        setGroup(ga, bEnemy);
                        enemies[aEnemy] = bEnemy;
                        enemies[bEnemy] = aEnemy;
                    }
                } else if (aHasEnemy) {
                    int aEnemy = enemies[ga];
                    setGroup(gb, aEnemy);
                } else if (bHasEnemy) {
                    int bEnemy = enemies[gb];
                    setGroup(ga, bEnemy);
                } else {
                    enemies[ga] = gb;
                    enemies[gb] = ga;
                }
            } else {
                cout << "nani\n";
            }
        } else {  // query for relations
            if (ga == NO_GROUP || gb == NO_GROUP) {
                cout << "none\n";
            } else if (ga == gb) {
                cout << "friend\n";
            } else if ((enemies.find(ga) != enemies.end() &&
                        enemies[ga] == gb) ||
                       (enemies.find(gb) != enemies.end() &&
                        enemies[gb] == ga)) {
                cout << "enemy\n";
            } else {
                cout << "none\n";
            }
        }
    }
}