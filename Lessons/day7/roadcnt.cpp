#include <bits/stdc++.h>
using namespace std;

// 用21位的二进制数储存当前遍历的状态
// dp[i][j] 表示 当前i所表示状态下到达j楼时的方案总和
long long dp[1<<21][25];
bool graph[25][25];

inline int gcd(int a, int b){
	return b==0 ? a : gcd(b, a%b);
}

int main() {
    long long res;

    // 建图
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (gcd(i, j) == 1)
            graph[i-1][j-1] = graph[j-1][i-1] = true;
            else
            graph[i-1][j-1] = graph[j-1][i-1] = false;
        }
    }
    dp[1][0] = 1;
    for (int i = 1; i < (1<<21); i++) {
        for (int j = 0; j < 21; j++) {
            if (!(i>>j & 1)) 
            continue;

            // 从j楼走向下一个k楼需满足：
            // 1. k楼未被访问  2. j k两楼有连接
            for (int k = 0; k < 21; k++) {
                if ((i>>k & 1) || !graph[j][k])
                continue;

                dp[i + (1<<k)][k] += dp[i][j];
            }
        }
    }

    // 计算所有21位都是1的方案总和
    for (int j = 0; j < 21; j++) {
        res += dp[(1<<21) - 1][j];
    }

    cout << res << endl;

    return 0;
}