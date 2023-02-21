#include <bits/stdc++.h>
using namespace std;
int grid[15][15];
int visit[15][15];
int ans = 10000;
int sum = 0;
int m, n;

void dfs(int x, int y, int cnt, int s) {
    if (2 * s > sum) return;
    if (2 * s == sum) {
        if (cnt < ans && visit[0][0]) {
            ans = cnt;
            return;
        }
    }
    visit[x][y] = 1;
    if (x-1 >= 0 && x-1 < n && y >= 0 && y < m && visit[x-1][y] == 0)
    dfs(x-1, y, cnt++, s+grid[x][y]);

    if (x+1 >= 0 && x+1 < n && y >= 0 && y < m && visit[x+1][y] == 0)
    dfs(x+1, y, cnt++, s+grid[x][y]);

    if (x >= 0 && x < n && y-1 >= 0 && y-1 < m && visit[x][y-1] == 0)
    dfs(x, y-1, cnt++, s+grid[x][y]);

    if (x >= 0 && x < n && y+1 >= 0 && y+1 < m && visit[x][y+1] == 0)
    dfs(x, y+1, cnt++, s+grid[x][y]);

    visit[x][y] = 0;
}

int main() {
    cin >> m >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            sum += grid[i][j];
        }
    }
    dfs(0, 0, 1, sum);

    cout << ans << endl;
}