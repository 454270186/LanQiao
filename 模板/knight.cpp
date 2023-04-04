#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int dp[maxn];
int n;

int main() {
    cin >> n;
    vector<int> d;
    int max_d = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        d.push_back(num);
    }

    dp[0] = 1;
    max_d = d[0];
    for (int i = 1; i < n; i++) {
        if (max_d < d[i]) {
            max_d = d[i];
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = dp[i-1];
        }
    }

    cout << dp[n-1] << endl;

}