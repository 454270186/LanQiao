#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, m, wn, ls;

struct Player {
    int s, w, id;
    bool operator<(const Player &x) const {
        if (x.s != s) return s > x.s;
        return id < x.id;
    }
} P[N], winner[N], loser[N];

// 归并排序
signed main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n * 2; ++i) P[i].id = i;
    for (int i = 1; i <= n * 2; ++i) cin >> P[i].s;
    for (int i = 1; i <= n * 2; ++i) cin >> P[i].w;
    sort(P + 1, P + 1 + n * 2);
    while (m--) {
        wn = ls = 0;
        for (int i = 1; i <= n; ++i) {
            if (P[i * 2].w > P[i * 2 - 1].w) {
                P[i * 2].s++;
                winner[++wn] = P[i * 2];
                loser[++ls] = P[i * 2 - 1];
            } else {
                P[i * 2 - 1].s++;
                winner[++wn] = P[i * 2 - 1];
                loser[++ls] = P[i * 2];
            }
        }
        merge(loser + 1, loser + 1 + n, winner + 1, winner + 1 + n, P + 1);
    }
    cout << P[q].id << '\n';
    return 0;
}