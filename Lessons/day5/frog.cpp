#include <bits/stdc++.h>
using namespace std;
int sum[1000005]; // sum[i]表示从起点到第i个石头的高度之和
int n, x;

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