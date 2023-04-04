#include <bits/stdc++.h>
using namespace std;

struct stuff {
    int w, v;
    stuff() {}
    stuff(int w, int v) {
        this->w = w;
        this->v = v;
    }
} e[105];

int V, N;
int dp[105][1005];
// dp[i][j] 表示在前i个物品中，且背包容量为j时，背包中物品的最大价值
int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        e[i] = stuff(w, v);
    }    
    for (int i = 0; i <= V; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= e[i].w) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-e[i].w] + e[i].v);
            }
        }
    }

    cout << dp[N][V] << endl;
}