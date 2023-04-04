#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m;
int pre[maxn];

int find(int x) {
    if (pre[x] == x) return x;
    return pre[x] = find(pre[x]); // 路径压缩，每一次查找都压缩树的高度
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
    }
    int op, x, y;
    while (m--) {
        cin >> op >> x >> y;
        if (op == 2) {
            if (find(x) == find(y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (op == 1) {
            int tx = find(x);
            int ty = find(y);
            if (tx != ty) {
                pre[ty] = tx;
            }
        }
    }
}