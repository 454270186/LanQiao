#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 410;

int n, m, q;
long long dist[maxn][maxn];

// 在n较小时，用floyd算法简单
int main() {
    memset(dist, INF, sizeof(dist));
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        int st, ed;
        cin >> st >> ed;
        if (dist[st][ed] >= INF)
        cout << "-1" << endl;
        else
        cout << dist[st][ed] << endl;
    }
}