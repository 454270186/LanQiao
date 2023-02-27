#include <bits/stdc++.h>
using namespace std;
int sum[1000005]; // sum[i]表示从起点到第i个石头的高度之和
int n, x;

/*
    假设情况：
    跳跃能力d = 3, 上课x天
    岸，1，2，3，|4，5，6，|7，8，9，岸

    要想总过河次数 >= 2x, 区间[1, 3]的石头的可被踩总数一定要 >= 2x
    (原因：因为从岸出发第一步贪心跳到3，3如果跳光了跳2，2跳光了跳1，所以第一步的跳跃次数等于区间[1, 3]的石头高度总和)
    又因为贪心从1可以跳到4，所以4的石头高度一定要可以容纳1的跳跃次数，故4石头高度 >= 1石头高度
    故区间[2, 4]的石头高度之和一定>=区间[1, 3]的石头高度之和，以此类推

    综上可以得出，若跳跃能力d合法，任意区间[i, i+d]的石头高度之和一定>=2x;
*/


bool check(int mid) {
    for (int i = 1; i + mid <= n; i++) {
        if (sum[i+mid-1] - sum[i-1] < 2*x) 
        return false;
    }

    return true;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n - 1; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }

    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (check(mid)) 
        right = mid;
        else
        left = mid + 1;
    }

    cout << right;
}