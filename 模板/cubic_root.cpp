#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8; // 精确到小数点后八位

double cubic_root(double x) {
    double l = 0, r = x;
    while (r - l > eps) {
        double mid = (r + l) / 2;
        if (mid * mid * mid < x) {
            l = mid; // 不能mid+1，精度跨度太大
        } else {
            r = mid;
        }
    }

    return l;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        double ans = cubic_root(num);
        cout << setprecision(3) << fixed << ans << endl;
    }
}