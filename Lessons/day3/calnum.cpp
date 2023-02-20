#include <bits/stdc++.h>
using namespace std;
int cnt = 1;

void add_num(int num) {
    if (num == 1) return;
    int half = num / 2;

    for (int i = 1; i <= half; i++) {
        add_num(i);
        cnt++;
    }
}

int main() {
    int n;
    cin >> n;
    add_num(n);

    cout << cnt << endl;

    return 0;
}