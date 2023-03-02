#include <bits/stdc++.h>
using namespace std;
int n;
int dp[101][10000]; 
int a[101][10000];
// dp[i][j] 表示走到(i, j) 时的最大合
// 转移方程： dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j]

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];

    // 遍历三角形
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
        }
    }

    // 在最后一层中找到最大值
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        ans = max(ans, dp[n][j]);
    }

    cout << ans << endl;
}