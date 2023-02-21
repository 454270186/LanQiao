#include <iostream>
using namespace std;

const int N = 2e5 + 5;

int main() {
    long long nums[N];
    long long sum[N];

    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum[i] = sum[i-1] + nums[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += nums[i] * (sum[n] - sum[i]);
    }

    cout << ans << endl;
    return 0;
}

// 前缀和