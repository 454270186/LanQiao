#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

long long dp[2025][2025];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{   
    return a * b / gcd(a, b);
}

int main() {
    for (int i = 1; i <= 2021; i++) {
        for (int j = 1; j <= 2021; j++) {
            if (i = j) dp[i][j] = 0;
            else if (abs(i - j) <= 21)
            dp[i][j] = dp[i][j] = lcm(i, j);
            else
            dp[i][j] = dp[j][i] = INF;
        }
    }


    for (int k = 1; k <= 2021; k++) {
        for (int i = 1; i <= 2021; i++) {
            for (int j = 1; j <= 2021; j++) {
                //if (dp[i][k] == 0 || dp[k][j] == 0) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << dp[1][2021] << endl;
}