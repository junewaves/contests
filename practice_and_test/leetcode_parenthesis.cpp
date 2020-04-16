#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool checkValidString(string s) {
        int n = s.size(), cnt_left = 0, cnt_ast = 0;
        if (n == 0)
            return true;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt_left++;
                a.push_back(i);
            } else if (s[i] == '*') {
                cnt_ast++;
                b.push_back(i);
            } else if (s[i] == ')') {
                if (cnt_left == 0 && cnt_ast == 0)
                    return false;
                else if (cnt_left > 0) {
                    cnt_left--;
                    a.pop_back();
                } else if (cnt_ast > 0) {
                    cnt_ast--;
                    b.pop_back();
                }
            }
        }
        if (cnt_left == 0)
            return true;
        if (cnt_left > cnt_ast)
            return false;
        int i = 0, j = 0, cnt = 0;
        while (i < cnt_left && j < cnt_ast) {
            if (a[i] < b[j]) {
                cnt++;
                i++;
            } else {
                if (cnt)
                    cnt--;
                j++;
            }
        }
        if (i < cnt_left)
            cnt += cnt_left - i;
        return cnt <= cnt_ast - j;
    }
};
int main() {
    string s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
    cout << Solution::checkValidString(s) << endl;
}