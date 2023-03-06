// 2194 出差
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 20010; // 双向边的最大数量

int t[M]; // 隔离时间
int dis[M]; // dis[i]表示点i到起点的距离

struct edge {
    int from;
    int to;
    int w;

    edge(int a, int b, int c) {
        from = a;
        to = b;
        w = c;
    }

    edge() {}
} e[M];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        e[i] = edge(u, v, c);
        e[m+i] = edge(v, u, c);
    }

    // bellman_ford
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;

    // 遍历n轮
    // 每轮都遍历每一条边
    // 每一轮操作都至少更新一个结点到起点的最短路径
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= 2*m; i++) {
            int u = e[i].from, v = e[i].to;
            int isolate = t[v];
            if (v == n) isolate = 0; // 终点不用隔离

            dis[v] = min(dis[v], dis[u] + e[i].w + isolate);
        }
    }

    cout << dis[n];
}