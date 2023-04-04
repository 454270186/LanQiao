#include <bits/stdc++.h>
using namespace std;

int n, m;

int get_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

bool cmp(int a, int b) {
    if (get_sum(a) == get_sum(b)) {
        return a < b;
    }

    return get_sum(a) < get_sum(b);
}

int main() {
    cin >> n >> m;

    //int nums[1000000];
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        //nums[i] = i;
        nums.push_back(i);
    }

    //sort(nums+1, nums+1+n, cmp);
    sort(nums.begin(), nums.end(), cmp);

    cout << nums[m-1];

}