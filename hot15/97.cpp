#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int nums[maxn];
int sum[maxn];
int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum[i] += sum[i-1] + nums[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += nums[j];
            if (sum % k == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}