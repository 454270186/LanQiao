// 灭鼠先锋
#include <bits/stdc++.h>
using namespace std;

// 博弈论核心：
// 1. 只能转移到必胜态的，均为必败态
// 2. 可以转移到必败态的，均为必胜态
// 根据此思想进行递归

unordered_map<string, bool> m;

bool check(string s) {
    return count(s.begin(), s.end(), '0') == 1;
}


bool dfs(string s) {
    if (m.count(s)) {
        return m[s];
    }
    if (check(s)) {
        // s 为必败态
        m[s] = false;
        return m[s];
    }

    // 下一个棋子
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'X') {
            string temp = s;
            temp[i] = 'X';
            if (!dfs(temp)) {
                m[s] = true;
                return m[s];
            }
        }
    }

    // 下两个棋子
    for (int i = 0; i < s.size(); i++) {
        if (i == 3 || i == 7) continue;

        if (s[i] != 'X' && s[i+1] != 'X') {
            string temp = s;
            temp[i] = temp[i+1] = 'X';
            if (!dfs(temp)) {
                m[s] = true;
                return m[s];
            }
        }
    }

    m[s] = false;
    return m[s];
}

int main() {
    string s[4] = {"X0000000", "XX000000", "0X000000", "0XX00000"};
    for (auto str : s) {
        cout << (dfs(str) ? 'L' : 'V');
    }

    return 0;
}