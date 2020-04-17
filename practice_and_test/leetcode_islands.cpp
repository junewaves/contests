#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int islands = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    BFS(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    static void BFS(int a, int b, vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;
        q.push({ a, b });
        grid[a][b] = '0';
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i > 0 && grid[i - 1][j] == '1') {
                q.push({ i - 1, j });
                grid[i - 1][j] = '0';
            }
            if (i < r - 1 && grid[i + 1][j] == '1') {
                q.push({ i + 1, j });
                grid[i + 1][j] = '0';
            }
            if (j > 0 && grid[i][j - 1] == '1') {
                q.push({ i, j - 1 });
                grid[i][j - 1] = '0';
            }
            if (j < c - 1 && grid[i][j + 1] == '1') {
                q.push({ i, j + 1 });
                grid[i][j + 1] = '0';
            }
        }
        return;
    }
};
int main() {
    //[['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]
    vector<vector<char>> input = { { '1', '1', '1', '1', '0' },
                                   { '1', '1', '0', '1', '0' },
                                   { '1', '1', '0', '0', '0' },
                                   { '0', '0', '0', '0', '0' } };
    cout << Solution::numIslands(input) << endl;
}