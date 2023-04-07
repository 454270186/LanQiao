#include <bits/stdc++.h>
using namespace std;

int n;
int nums[105][105];
int dp[105][105] = {0};
int left_cnt = 0;
int right_cnt = 0;
int mid;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> nums[i][j];
        }
    }

    // dp[i][j] = dp[i-1][j] || dp[i-1][j-1]
    mid = (mid % 2 == 0) ? (n / 2) : (n / 2 + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (left_cnt >= mid) {
                dp[i][j] = nums[i][j] + dp[i-1][j-1];
            } else if (right_cnt >= mid) {
                dp[i][j] = nums[i][j] + dp[i-1][j];
            } else if (left_cnt < mid && right_cnt < mid) {
                if (dp[i-1][j] >= dp[i-1][j-1]) {
                    dp[i][j] = nums[i][j] + dp[i-1][j];
                    if (i == 1) continue;
                    left_cnt++;
                } else {
                    dp[i][j] = nums[i][j] + dp[i-1][j-1];
                    if (i == 1) continue;
                    right_cnt++;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;
}