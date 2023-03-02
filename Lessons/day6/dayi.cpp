#include <bits/stdc++.h>
#define int long long // 注意整数大小，此题用int过不了全部答案
using namespace std;

struct stu
{
    int s, a, e;
} stus[100000];

bool cmp(stu a, stu b) {
    return a.a+a.e+a.s < b.a+b.e+b.s;
}

int n;
int res = 0;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stus[i].s >> stus[i].a >> stus[i].e;
    }

    sort(stus+1, stus+n+1, cmp);

    for (int i = 1; i <= n; i++) {
        res += (n - i + 1) * (stus[i].s + stus[i].a) + (n - i) * stus[i].e;
    }

    cout << res;
    return 0;
}