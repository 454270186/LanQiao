#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int ans = 1;
    set<pair<int, int>> lines;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, b;
        cin >> k >> b;

        if (lines.find({k, b}) != lines.end()) {
            continue;
        }

        ans++;

        set<pair<double, double>> points;
        for (auto it = lines.begin(); it != lines.end(); it++) {
            if (k == it->first) {
                continue;
            }

            double x = (it->second - b) * 1.0 / (k - it->first);
            double y = k * x + b;

            if (points.find({x, y}) != points.end()) {
                continue;
            }

            ans++;

            points.insert(make_pair(x, y));
        }

        lines.insert(make_pair(k, b));
    }    

    cout << ans << endl;

    return 0;
}