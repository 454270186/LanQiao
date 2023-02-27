#include <bits/stdc++.h>
using namespace std;
int stones[50000];
int len, n, m;

bool check(int d) {
    int pos = 0; // current position
    int cnt = 0; // the count of moved stones

    for (int i = 1; i <= n; i++) {
        if (stones[i] - pos < d)
        cnt++;
        else
        pos = stones[i];
    }

    if (cnt <= m) return true;
    else return false;
}

int main () {
    cin >> len >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> stones[i];
    }

    int left = 0, right = len, ans;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(mid))
        left = mid + 1;
        else 
        right = mid - 1;
    }

    if (!check(left)) left--;

    cout << left;
}