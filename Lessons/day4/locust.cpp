#include <bits/stdc++.h>
using namespace std;
/*
    思路：
        1.求最少跳跃，也就是最短路径问题，想到bfs
        2. 很多蚱蜢在一起跳，十分杂乱不好分析，可以看成只有空盘在跳
        3. 圆圈不好分析 ==> 化圆为线，用数组存储圆圈里的数
        4. 每一层拓展4个状态，直到找到答案


    经典的八数码问题
    还需要处理去重的问题, 避免往回跳

    012345678 ==> 087654321
*/
string origin = "012345678";
unordered_map<string, bool> hashmap;
struct node {
    node(){}
    node(string ss, int tt) {
        s = ss;
        t = tt;
    }

    string s;
    int t;
};
queue<node> q;

void bfs() {
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        string str = now.s;
        int step = now.t;
        if (str  == "087654321") {
            // 找到答案
            cout << step << endl;
            break;
        }

        // 开始跳跃
        
        int i = 0;
        while (str[i] != '0') i++;  // 先找到0所在位置
        for (int j = i-2; j <= i+2; j++) {
            int k = (j + 9) % 9; // 转化负数
            if (k == i) continue;

            //  swap(str[i], str[k]); 大错特错之！
            //  不能直接在原str上修改，因为之后还有别的情况要搜索，所以要维护原str


            string new_str = str;
            swap(new_str[k], new_str[i]);

            // 去重
            if (hashmap.find(new_str) == hashmap.end()) {
                hashmap[new_str] = true;
                q.push(node(new_str, step + 1));
            }
        }
    }
}


int main() {
    node now = node(origin, 0);
    q.push(now);
    bfs();
    return 0;
}