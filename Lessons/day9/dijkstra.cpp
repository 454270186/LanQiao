#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 3e5 + 2;

struct edge {
    int from, to, w;
    edge(int a, int b, int c) {
        from = a;
        to = b;
        w = c;
    }
};
vector<edge> e[N];  // e[i] 储存结点i的所有edge

struct s_node {
    int id; // 结点编号
    long long dis; // 结点到起点的距离

    s_node(int id, long long dis) {
        this->id = id;
        this->dis = dis;
    }
    bool operator < (const s_node& a) {
        return dis > a.dis;
    }
};

int n, m;
int pre[N]; // 记录前驱结点 用来打印路径
void print_path(int s, int t) {
    if (s == t) cout << s << " ";
    print_path(s, pre[t]);
    cout << t << " ";
}
long long dis[N]; // 储存所有结点到起点的距离

void dijkstra() {
    int s = 1; // 起点为1
    bool done[N]; // done[i] == true 表示结点i的最短路径已找到

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        done[i] = false;
    }
    dis[s] = 0;
    priority_queue<s_node> q;
    q.push(s_node(s, dis[s]));

    while (!q.empty()) {
        s_node u = q.top();
        q.pop();
        if (done[u.id]) continue;
        done[u.id] = true;

        // 遍历u的所有边
        for (int i = 0; i < e[u.id].size(); i++) {
            edge y = e[u.id][i];
            if (done[y.to]) continue;
            if (dis[y.to] > y.w + u.dis) {
                dis[y.to] = y.w + u.dis;
            }
            q.push(s_node(y.to, dis[y.to]));
            pre[y.to] = u.id;
        }
    }

    print_path(1, n);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        e[u].push_back(edge(u, v, w));
        e[v].push_back(edge(v, u, w));
    }
    dijkstra();
}