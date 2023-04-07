#include <bits/stdc++.h>
using namespace std;

int a, b;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string s;
int cnt = 0;
unordered_map<string, int> str_cnt;
queue<string> q;

void bfs() {
    q.push(s);
    str_cnt[s] = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        int dis = str_cnt[u];
        if (u.find('A') == b && u.find('B') == a) {
            cout << dis << endl;
            return;
        }

        int pos = u.find(' ');
        int x = pos / 3, y = pos % 3;

        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx < 0 || dx > 1 || dy < 0 || dy > 2) {
                continue;
            }
            swap(u[pos], u[dx * 3 + dy]);
            if (str_cnt[u] == 0) {
                str_cnt[u] = dis + 1;
                q.push(u);
            }
            swap(u[pos], u[dx * 3 + dy]);
        }
    }
    
}

int main() {
    string t;
    for (int i = 0; i < 2; i++) {
        getline(cin, t);
        s += t;
    }

    a = s.find('A');
    b = s.find('B');

    bfs();

    return 0;
}