#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

struct edge {
    int from;
    int to;
    long long w;
    edge(int u, int v, long long w) {
        from = u;
        to = v;
        this->w = w;
    }
};
vector<edge> e;
long long dist[maxn];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e.push_back(edge(u, v, w));
    }
    memset(dist, INF, sizeof(dist));
    dist[1] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < e.size(); i++) {
            int u = e[i].from;
            int v = e[i].to;

            dist[v] = min(dist[v], dist[u] + e[i].w);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << ' ';
    }
}