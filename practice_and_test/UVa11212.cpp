#include <bits/stdc++.h>
using namespace std;

int n, mxd;
int evaluate(const vector<int>& arr) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1] + 1)
            res++;
    }
    return res + (arr[n - 1] != n);
}
void cut(vector<int>& arr, int s, int e, int l) {
    vector<int> va(n), vb(n);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i < s || i > e)
            va[a++] = arr[i];
        else
            vb[b++] = arr[i];
    }
    int i = 0;
    for (; i < l; i++)
        arr[i] = va[i];
    for (; i < l + b; i++)
        arr[i] = vb[i - l];
    for (; i < n; i++)
        arr[i] = va[i - b];
}
bool dfs(int d, vector<int>& arr) {
    int h = evaluate(arr);
    if (h == 0)
        return true;
    if (3 * d + h > 3 * mxd)
        return false;
    vector<int> tmp(n);
    for (int s = 0; s < n; s++) {
        for (int e = s; e < n; e++) {
            for (int l = 0; l < n - (e - s + 1); l++) {
                copy(arr.begin(), arr.end(), tmp.begin());
                cut(arr, s, e, l);
                if (dfs(d + 1, arr))
                    return true;
                copy(tmp.begin(), tmp.end(), arr.begin());
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 0;
    while (1) {
        cin >> n;
        if (!n)
            break;
        vector<int> input(n);
        for (int& it : input)
            cin >> it;
        for (mxd = 0; mxd < n; ++mxd)
            if (dfs(0, input))
                break;
        cout << "Case " << ++c << ": " << mxd << '\n';
    }
}
