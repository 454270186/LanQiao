#include <bits/stdc++.h>
using namespace std;

// dfs + 剪枝
bool friends[105][105]{false};
int p[105][105]{0}; // p[i][j] 表示第i间教室的第j个位置
int ans = 0x3f3f3f3f;
int n, m;

void dfs(int id, int classes){
    // 剪枝
    if (classes >= ans) {
        return;
    }

    if (id > n) {
        ans = min(ans, classes);
    }

    for (int class_num = 1; class_num <= classes; class_num++) {
        int class_pos = 1;
        while (p[class_num][class_pos] && !friends[id][p[class_num][class_pos]]){
            class_pos++;
        }
        if (p[class_num][class_pos] == 0) {
            p[class_num][class_pos] = id;
            dfs(id+1, classes);
            p[class_num][class_pos] = 0;
        }
    }

    // 如果已有教室都不能坐的话，新开一间教室
    p[classes+1][1] = id;
    dfs(id+1, classes+1);
    p[classes+1][1] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a][b] = true;
        friends[b][a] = true;
    }

    dfs(1, 1);

    cout << ans << endl;
}















