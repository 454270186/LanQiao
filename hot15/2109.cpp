#include <bits/stdc++.h>
using namespace std;

int pre_sum[550][550]; // pre[i][j] 记录第i行时，前j个的前缀和

// 前缀和 + 滑动窗口
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num;
            cin >> num;
            pre_sum[i][j] = pre_sum[i-1][j] + num; // s[i][j]：第j列上，第0～i行数字的前缀和
        }
    }

    long long ans = 0;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1; i2 <= n; i2++) {
            long long sum = 0;
            for (int j1 = 1, j2 = 1; j2 <= m; j2++) {
                sum += pre_sum[i2][j2] - pre_sum[i1-1][j2];
                while (sum > k) {
                    sum -= pre_sum[i2][j1] - pre_sum[i1-1][j1];
                    j1++;
                }

                ans += j2 - j1 + 1;
            }
        }
    }

    cout << ans << endl;
}