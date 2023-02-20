#include <bits/stdc++.h>
using namespace std;
int remains[10] = {2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021};

int main() {
    int cnt = 1;

    while (true) {
        int number = cnt;
        while (number > 0) {
            int x = number % 10;
            if (remains[x] == 0) {
                cout << cnt-1 << endl; // 最后一次cnt不能成功摆出卡片，所以不能算在内
                return 0;
            }
            remains[x]--;
            number /= 10;
        }

        cnt++;
    }
}