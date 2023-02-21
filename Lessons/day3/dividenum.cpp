#include <bits/stdc++.h>
using namespace std;
/*  
    divide(n, m)表示将整数n拆分成m块的方案数
    两种情况：
    1. 选1：
        那么一定有一块确定是1，所以将剩下的再划分 divide(n-1, m-1)
    2. 不选1：
        将n拆分为m块 等价于 将每一块都减去1，然后将剩下的数拆分成m块
        即 divide(n-m, m)
*/

int divide(int n, int m) {
    if (m == 0 || n < m) return 0;
    if (m == 1 || n == m) return 1;
    else {
        return divide(n-1, m-1) + divide(n-m, m);
    }
}


int main() {
    int n, k;
    cin >> n >> k;

    cout << divide(n, k) << endl;
    return 0;
}