#include <bits/stdc++.h>
using namespace std;
int chocolate[100000][2];
int n, k;
/*
    对巧克力边长二分
*/

bool check(int d) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += (chocolate[i][0] / d) * (chocolate[i][1] / d);
    }
    if (num >= k) return true;
    else return false;
}



int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> chocolate[i][0] >> chocolate[i][1];
    }

    // 二分边长
    int l = 0, r = 100010;
    while (l < r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    if (!check(l)) l--;

    cout << l << endl;
}