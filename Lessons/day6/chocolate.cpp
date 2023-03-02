#include <bits/stdc++.h>
using namespace std;

/*
    priority_queue<Type, Container, Functional>
    只使用第一个参数的时候默认以vector作为容器，以operator<为比较方式
    所以priority_queue默认为一个大顶堆
*/

/*
    思路：
    单独对价格贪心或者单独对保质期贪心都不太完美
    所以贪心思路为：将巧克力尽量放到快过期的时候吃，然后在当天再选择最便宜的巧克力吃


*/

int days, kinds;
struct chocolate
{
    int scale;
    int left_day;
    int amount;

    // 重载priority_queue的默认<比较符
    // 使这个优先队列变为小顶堆
    friend bool operator < (chocolate A, chocolate B) {
        return A.scale > B.scale;
    } 
} all_cho[100000];
priority_queue<chocolate> q;

bool cmp(chocolate a, chocolate b) {
    return a.left_day < b.left_day;
}

int main() {
    int res;
    cin >> days >> kinds;
    for (int i = 1; i <= kinds; i++) {
        cin >> all_cho[i].scale >> all_cho[i].left_day >> all_cho[i].amount;
    }

    sort(all_cho+1, all_cho+kinds+1, cmp);

    int kind = kinds;
    // 从最后一天开始往前遍历
    for (int i = days; i >= 1; i--) {
        // 每一天都要确认一下今天的候选巧克力
        // 因为巧克力已经按保持期升序排序好
        // 所以从保质期最长的开始看
        // 若当前巧克力保质期比天数长，说明可以在这一天吃
        // 将其压入优先队列中
        while (all_cho[kind].left_day >= i) {
            q.push(all_cho[kind]);
            kind--;
        }

        if (q.size() == 0) {
            res = -1;
            break;
        }

        // 再从今天的所有候选巧克力中买一块最便宜的吃
        chocolate now = q.top(); // 今天买一个最便宜的
        q.pop();
        res += now.scale;
        now.amount--;
        // 这种巧克力没吃完，压回队列
        // 因为今天能吃，昨天肯定也能吃
        if (now.amount > 0) q.push(now);
    }

    cout << res << endl;

}
