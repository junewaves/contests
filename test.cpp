#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static array<char, 26> key(string& s) {
        array<char, 26> tmp = { 0 };
        for (char c : s) {
            tmp[c - 'a']++;
        }
        return tmp;
    }
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<char, 26>, vector<string>> storage;
        for (string& s : strs) {
            storage[key(s)].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto p : storage) {
            vector<string> t;
            for (string& str : p.second) {
                t.emplace_back(str);
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};

char a[] = "abcdefghijklmnopqrstuvwxyz";
vector<string> gen() {
    vector<string> ret;
    for (int i = 0; i < 100; i++) {
        // random_shuffle(a, a + 5);
        string s;
        for (int j = 0; j < 10; j++) {
            s += a[rand() % 5];
        }
        ret.emplace_back(s);
        // cout << *ret.rbegin() << endl;
    }
    return ret;
}
int main(int argc, char* argv[]) {
    srand(6);
    vector<vector<string>> ans;
    vector<string> input = gen();
    ans = Solution::groupAnagrams(input);
    cout << "-----------" << endl;
    cout << ans.size() << endl;
    for (auto v : ans) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}
