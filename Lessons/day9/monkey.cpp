#include <bits/stdc++.h>
using namespace std;

int m, n;
int monkeys[5005];
int tree_pos[5005][2];
int pre[5005];

struct edge
{
    int u, v;
    double weight;

    edge(int a, int b, double c) {
        u = a;
        v = b;
        weight = c;
    }
};
vector<edge> e;


bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

int find(int x) {
    if (pre[x] != x) pre[x] = find(pre[x]);
    return pre[x];
}

int main() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> monkeys[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tree_pos[i][0];
        cin >> tree_pos[i][1];
    }

    //初始化并查集
    for (int i = 1; i <= n; i++) {
        pre[i] = i; 
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int u = i, v = j;
            double w = sqrt((tree_pos[i][0]-tree_pos[j][0])*(tree_pos[i][0]-tree_pos[j][0]) + (tree_pos[i][1] - tree_pos[j][1])*(tree_pos[i][1] - tree_pos[j][1]));
            e.push_back(edge(u, v, w));
        }
    }

    sort(e.begin(), e.end(), cmp);
    // kruskal 建立最小生成树
    int edge_cnt = 0;
    double max_w = 0.0;
    for (int i = 0; i < e.size(); i++) {
        // 若不在同一集合中，建边
        if (find(e[i].u) != find(e[i].v)) {
            pre[e[i].v] = find(e[i].u);
            edge_cnt++;
            max_w = max(max_w, e[i].weight);

            if (edge_cnt == n-1) {
                break; 
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (monkeys[i] >= max_w)
        ans++;
    }

    cout << ans << endl;
}