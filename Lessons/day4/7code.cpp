#include <bits/stdc++.h>
using namespace std;
const int N=10;
int use[N],ans,e[N][N],fa[N];
/*
    a b c d e f g
    1 2 3 4 5 6 7

    1. 用无向图储存数码管之间的关系
    2. dfs遍历每一种情况并用并查集记录
    3. 遍历并查集看有几个集合，只有一个集合即为可行

*/
void init() {
    /*	
		连边建图，e[i][j]==1表示i和j相邻
		a b c d e f g
		1 2 3 4 5 6 7
	*/
    e[1][2]=e[1][6]=1;
	e[2][1]=e[2][7]=e[2][3]=1;
	e[3][2]=e[3][4]=e[3][7]=1;
	e[4][3]=e[4][5]=1;
	e[5][4]=e[5][6]=e[5][7]=1;
	e[6][1]=e[6][5]=e[6][7]=1;
}

int find(int x) {
    if (fa[x] == x)
    return x;

    return find(fa[x]);
}

void dfs(int d) {
    if (d > 7) {
        // 7根数码管都已经点亮，开始判断

        // 先初始化为7个集合，然后开始合并
        // 如果两个集合相邻且都开灯，则合并为同一个集合
        // 最后检验集合的个数
        for (int i = 1; i <= 7; i++)
        fa[i] = i;

        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j <= 7; j++) {
                if (e[i][j] && use[i] && use[j]) {
                    int fx = find(i);
                    int fy = find(j);
                    if (fx != fy) {
                        fa[fx] = fy;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= 7; i++) {
            if (use[i] && fa[i] == i)
            cnt++;
        }

        if (cnt == 1)
        ans++;

        return;
    }
    use[d] = 1; // 打开当前数码管，继续开关下一个
    dfs(d+1);
    use[d] = 0; // 关闭当前数码管，继续开关下一个
    dfs(d+1);
}



int main() {
    init();
    dfs(1);
    cout << ans;
}
