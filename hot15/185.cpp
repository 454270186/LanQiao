#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int p[N];
int n;

int find(int x) {
    if (x == p[x]) {
        return x;
    }

    p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n;
    for(int i = 0; i < N; i ++) p[i] = i;
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        x = find(x);
        printf("%d ", x);
        p[x] = x + 1;
    }
    return 0;
}

/*
    hashset 超时
*/
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     set<int> hashset;
//     hashset.insert(nums[0]);
    

//     for (int i = 1; i < nums.size(); i++) {
//         while (hashset.find(nums[i]) != hashset.end()) {
//             nums[i]++;
//         }
//         hashset.insert(nums[i]);
//     }

//     for (int i = 0; i < nums.size(); i++) {
//         cout << nums[i] << " ";
//     }

//     cout << endl;
// }