/*
    思路：
    1. 数学等价： 青蛙从左到右跳x次+从右到左跳x次 == 青蛙从左到右跳2x次
    2. 二分查找青蛙的跳跃能力。若mid可以跳过，则mid++都可以跳过；若mid跳不过，则mid--都不可以跳过
    3. 用并查集记录路径
*/

#include <iostream>
using namespace std;
const int N = 1e5 + 10;

long long riverWidth;
long long days;
long long stones[N];
long long pre[N];
long long sum[N];
long long vb[N];

long long find(long long x) {
    if (x != pre[x])
    pre[x] = find(x);

    return pre[x];
}

bool check(int mid) {
    for (int i = 0; i <= riverWidth; i++) {
        pre[i] = i;
        sum[i] = 0;
    }
    for (int i = 1; i < riverWidth; i++) {
        vb[i] = stones[i];
    }

    sum[0] = 2 * days;

    for (int i = 0; i < riverWidth; i++) {
        int idx = i + mid;

        if (idx >= riverWidth) {
            sum[riverWidth] += sum[i];
        }

        
    }



    return true;
}


int main() {
    cin >> riverWidth >> days;
    for (int i = 1; i < riverWidth; i++) {
        cin >> stones[i];
    }

    int l = 1, r = riverWidth;
    while(l < r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;    
}
