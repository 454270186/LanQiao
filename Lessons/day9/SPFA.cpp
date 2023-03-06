// 1366 随机数据下的最短路问题
#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
const long INF = 0x3f3f3f3f;

struct edge {
    int from, to;
    long long w;

    edge(int a, int b, long long c) {
        from = a;
        to = b;
        w = c;
    }
};
vector<edge> e[N];
long long dis[N];
bool isInQueue[N]; // 记录结点是否在队列中

int n, m, s;

void spfa() {
    memset(dis, INF, sizeof(dis));
    dis[s] = 0; // 起点到起点距离为0

    queue<int> q;
    q.push(s);
    isInQueue[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        isInQueue[u] = false;

        if (dis[u] == INF) continue;

        // 对u的所有邻居遍历
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].to;

            if (dis[v] > dis[u] + e[u][i].w) {
                dis[v] = dis[u] + e[u][i].w;
                if (!isInQueue[v]) {
                // 结点v到起点的最短路径被更新
                // 若v不在队列中，将它加入队列
                    q.push(v);
                    isInQueue[v] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        e[i].push_back(edge(a, b, c));
    }

    spfa();

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
}