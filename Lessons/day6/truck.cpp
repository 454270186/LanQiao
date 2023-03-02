#include <bits/stdc++.h>
using namespace std;
struct object
{
    double weight;
    double value;
    double scale;
} objs[10000];

bool cmp(object a, object b) {
    return a.scale > b.scale;
}

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    cin >> objs[i].weight >> objs[i].value;

    sort(objs, objs+n, cmp); 

    // 遍历货物
    // 开始贪心装箱
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (w >= objs[i].weight) {
            ans += objs[i].value;
            w -= objs->weight;
        } else {
            ans += w * objs[i].scale;
        }

        cout << setprecision(1) << fixed << ans;
    }
}