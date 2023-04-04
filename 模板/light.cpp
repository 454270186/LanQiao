#include <bits/stdc++.h>
using namespace std;
// 差分数组
// 构建一个差分数组，记录当前彩灯和前驱彩灯的差值
// 将每次区间加的复杂度降到O(1)
long long n, q;

int main() {
    cin >> n >> q;
    vector<long long>lights(n);
    for (int i = 0; i < n; i++) {
        cin >> lights[i];
    }

    vector<long long>diff(n+1, 0); // 差分数组
    for (long long i = 0; i < q; i++) {
        long long l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        if (r < n) {
            diff[r + 1] -= x;
        }
    }

    // 对差分数组进行前缀和操作
    for (long long i = 1; i <= n; i++) {
        diff[i] += diff[i-1];
        lights[i-1] += diff[i];
        if (lights[i-1] < 0) lights[i-1] = 0;
    }

    for (long long i = 0; i < n; i++) {
        cout << lights[i] << " ";
    }

    return 0;
}