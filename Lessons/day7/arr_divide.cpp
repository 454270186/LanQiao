// 2148 数组切分
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n;
int ans = 0;
// int nums[10010];
// int dp[10010];
int main() {
    cin >> n;
    vector<int> nums(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int Min = n+1, Max = 0;
        for (int j = i; j > 0; j--) {
            Min = min(Min, nums[j]);
            Max = max(Max, nums[j]);
            if (Max - Min == i - j) {
                dp[i] = (dp[i] + dp[j-1]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
}

