#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    vector<int> nxt(n), st;
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && a[st.back()] >= a[i])
            st.pop_back();
        nxt[i] = st.size() ? st.back() : n;
        st.push_back(i);
    }
    int prv = -1, ans = 0;
    st.clear();
    for (int i = 0; i < n; i++) {
        while (st.size() && a[st.back()] >= a[i])
            st.pop_back();
        prv = st.size() ? st.back() : -1;
        ans = max(ans, a[i] * (nxt[i] - prv - 1));
        st.push_back(i);
    }
    cout << ans << '\n';
    return 0;
}
