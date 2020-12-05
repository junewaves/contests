#include <bits/stdc++.h>
using namespace std;

void leave(int /*where*/) {
    // cerr << where << '\n';
    cout << "0\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        if (s == "1")
            cout << 20'000'000'000LL << '\n';
        else
            cout << 10'000'000'000LL << '\n';
        return 0;
    } else if (n == 2) {
        if (s == "10" || s == "11")
            cout << 10'000'000'000LL << '\n';
        else if (s == "01")
            cout << 9'999'999'999 << '\n';
        else 
            cout << "0\n";
        return 0;
    }
    int head = 0, mid = 0, tail = 0;
    if (s.substr(0, 1) == "0")
        head = 1;
    else if (s.substr(0, 2) == "10")
        head = 2;
    else if (s.substr(0, 3) == "110")
        head = 3;
    else
        leave(1);
    for (int i = head; i + 3 <= n; i += 3) {
        if (s.substr(i, 3) != "110") leave(2);
        mid++;
    }
    tail = (n - head) % 3;
    if (tail == 1) {
        if (s.substr(n - 1, 1) != "1")
            leave(3);
    } else if (tail == 2) {
        if (s.substr(n - 2, 2) != "11")
            leave(4);
    }
    mid++;
    if (tail) mid++;
    // int add = 0;
    // if (n % 3 == 0 && s.substr(0, 3) == "110")
    //     add = 1;
    cout << 10'000'000'000LL - mid + 1 << '\n';
    return 0;
}

// 11011