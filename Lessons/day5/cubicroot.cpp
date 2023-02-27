#include <bits/stdc++.h>
using namespace std;

// 实数二分要注意精度问题
// 一般来说：精确到小数点后3位，精度往后取两位(1e-5)

int main() {
    int n;
    cin >> n;

    while (n--) {
        double num;
        cin >> num;

        double l = 0, r = num;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;

            if (mid * mid * mid > num) {
                r = mid;
            } else if (mid * mid * mid <= num) {
                l = mid;
            }
        }
        cout << setprecision(3) << fixed << l << endl;
    }


    return 0;
}