#include <bits/stdc++.h>
using namespace std;
// 背包问题 动态规划

const int maxW = 1e5+10;
int N, sum, w[105];
int dp[105][maxW];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
        sum += w[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][abs(j-w[i])] + dp[i-1][j+w[i]];
        }
    }

    int count = 0;
    for (int i = 1; i <= sum; i++) {
        if (dp[N][i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
