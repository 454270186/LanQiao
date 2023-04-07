#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
struct node {
    int id;
    int ts;
};
node arr[maxn];
int likes[maxn];
set<int> ans;
int n, d, k;

int main() {
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].ts >> arr[i].id;
    }
    sort(arr+1, arr+n+1, [](node x, node y){return x.ts < y.ts;});
    int l = 1;
    for (int i = 1; i <= n; i++) {
        likes[arr[i].id]++;
        while (arr[i].ts - arr[l].ts >= d) {
            likes[arr[l].id]--;
            l++;
        }
        if (likes[arr[i].id] >= k) {
            ans.insert(arr[i].id);
        }
    }

    //sort(ans.begin(), ans.end());
    for (int num : ans) {
        cout << num << endl;
    }
}