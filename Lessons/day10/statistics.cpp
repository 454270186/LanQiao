// 535 统计数字
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int hash[200010];
    vector<int> nums;
    memset(hash, 0, sizeof(hash));

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        hash[num]++;
        if (hash[num] > 1) continue;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (int num : nums) {
        cout << num << " " << hash[num] << endl;
    }
}