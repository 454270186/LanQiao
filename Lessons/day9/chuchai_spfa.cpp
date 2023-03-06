#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 20010;

int n, m;
int t[maxn];

struct edge
{
    int from, to;
    long long w;
    edge(int a, int b, long long c) {
        from = a;
        to = b;
        w = c;
    }
};
vector<edge> e[maxn];
long long dis[maxn];
bool isInQue[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        e[u].push_back(edge(u, v, c));
        e[v].push_back(edge(u, v, c));
    }

    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    
    queue<int> q;
    q.push(1);
    isInQue[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        isInQue[u] = false;

        if (dis[u] == INF) continue;

        // 遍历u的每一条边
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].to;
            int isolate = t[v];
            if (v == n) isolate = 0;

            // dis[v] = min(dis[v], e[u][i].w + dis[u] + isolate);
            // if (!isInQue[v] && v > u) {
            //     q.push(v);
            //     isInQue[v] = true;
            // }

            if (dis[v] > e[u][i].w + dis[u] + isolate) {
                dis[v] = e[u][i].w + dis[u] + isolate;
                if (!isInQue[v]) {
                    q.push(v);
                    isInQue[v] = true;
                }
            }
        }
    }

    cout << dis[n] << endl;


}