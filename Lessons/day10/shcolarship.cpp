// 531 奖学金
#include <bits/stdc++.h>
using namespace std;

struct stu
{
    int id;
    int chi;
    int math;
    int eng;
    int total;

    stu(int a, int b, int c, int d) {
        id = a;
        chi = b;
        math = c;
        eng = d;
        total = chi + math + eng;
    }
};

bool cmp(stu a, stu b) {
    if (a.total != b.total) {
        return a.total > b.total;
    } else if (a.chi != b.chi) {
        return a.chi > b.chi;
    } else {
        return a.id < b.id;
    }
}


int main() {
    int n;
    cin >> n;
    vector<stu> stus;
    for (int i = 1; i <= n; i++) {
        int c, m, e;
        cin >> c >> m >> e;
        stus.push_back(stu(i, c, m, e));
    }

    sort(stus.begin(), stus.end(), cmp);

    for (auto stu : stus) {
        cout << stu.id << " " << stu.total << endl;
    }
}